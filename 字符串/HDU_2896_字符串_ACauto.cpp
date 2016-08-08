#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
#define maxnode 100010
#define sigma_size 93

int n, m;
char st[220];
char T[10010];
bool visit[510];
bool flag;

struct Trie{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int f[maxnode];
    int last[maxnode];
    int sz;
    Trie(){
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
    }
    int idx(int c){
        return c-33;
    }
    void insert(char *s, int v){
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++){
            int c = idx(s[i]);
            if(!ch[u][c]){
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }
    void getFail(){
        queue<int> q;
        f[0] = 0;
        for (int c = 0; c < sigma_size; c++){
            int u = ch[0][c];
            if(u){
                f[u] = 0;
                q.push(u);
                last[u] = 0;
            }
		}
            while(!q.empty()){
                int r = q.front();
                q.pop();
                for (int c = 0; c < sigma_size; c++){
                    int u = ch[r][c];
                    if(!u){
                        ch[r][c] = ch[f[r]][c];
                        continue;
                    }
                    q.push(u);
                    int v = f[r];
                    while(v && !ch[v][c]) v = f[v];
                    f[u] = ch[v][c];
                    last[u] = val[f[u]] ? f[u] : last[f[u]];
                }
            }
    }
    void find(char *t){
        int n = strlen(t);
        int j = 0;
        for (int i = 0; i < n; i++){
            int c = idx(t[i]);
            j = ch[j][c];
            if(val[j]){
                pt(j);
            }
            else if(last[j]){
                pt(last[j]);
            }
        }
    }
    void pt(int j){
        while(j){
            flag = true;
            visit[val[j]] = true;
            j = last[j];
        }
    }
};

int main()
{
    while(~scanf("%d", &n)){
        Trie *tr = new Trie();
        for (int i = 1; i <= n; i++){
            scanf("%s", st);
            tr->insert(st, i);
        }
        tr->getFail();
        scanf("%d", &m);
        int total = 0;
        for (int i = 1; i <= m; i++){
            flag = false;
            scanf("%s", T);
            tr->find(T);
            if(flag){
                total++;
                if(total > 1) printf("\n");
                printf("web %d:", i);
                for (int j = 1; j <= 500; j++){
                    if(visit[j]){
                        printf(" %d", j);
                        visit[j] = false;
                    }
                }
            }
        }
        printf("\ntotal: %d\n", total);
        delete tr;
    }
    return 0;
}
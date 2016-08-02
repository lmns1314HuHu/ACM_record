#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

#define maxnode 500005
#define sigma_size 26
int t, n;
char st[55];
int cnt;
char T[1000010];

struct Trie{
    int ch[maxnode][sigma_size];
    int f[maxnode];
    int last[maxnode];
    int val[maxnode];
    int sz;
    Trie(){
        sz = 1;
        memset(ch[0], 0, sizeof ch[0]);
        memset(val, 0, sizeof val);
        //memset(last, 0, sizeof last);
        //memset(f, 0, sizeof f);
    }
    int idx(char d){
        return d-'a';
    }

    void insert(char* s, int v){
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++){
            int c = idx(s[i]);
            if(!ch[u][c]){
                memset(ch[sz], 0, sizeof (ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] += v;
    }

    void getFail(){
        queue<int> q;
        f[0] = 0;
        for (int c = 0; c < sigma_size; c++){
            int u = ch[0][c];
            if(u) {
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

    void find(char* t){
        int n = strlen(t);
        int j = 0;
        for (int i = 0; i < n; i++){
            int c = idx(t[i]);
            j = ch[j][c];
            if(val[j]) pt(j);
            else if(last[j]) pt(last[j]);
        }
    }

    void pt(int j){
        while(j){
            cnt += val[j];
            val[j] = 0;
            j = last[j];
        }
    }

};

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        cnt = 0;
        Trie* tr = new Trie();
        for (int i = 0; i < n; i++){
            scanf("%s", st);
            tr->insert(st, 1);
        }
        tr->getFail();
        scanf("%s", T);
        tr->find(T);
        delete tr;
        printf("%d\n", cnt);
    }
    return 0;
}

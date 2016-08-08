#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

#define maxnode  150*75
#define sigma_size 26

int n;
char moshi[155][75];
char wenben[1000010];
int cnt[155];
map<string, int> ms;

struct Trie{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int f[maxnode];
    int last[maxnode];
    int sz;
    Trie(){
        sz = 1;
        memset(ch[0], 0, sizeof (ch[0]));
    }
    int idx(char c){
        return c-'a';
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
        val[u] = v;
        ms[string(s)] = v;
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
                last[u] = last[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
    void find(char* T){
        int n = strlen(T);
        int j = 0;
        for (int i = 0; i < n; i++){
            int c = idx(T[i]);
            j = ch[j][c];
            if(val[j]) pt(j);
            else if(last[j]) pt(last[j]);
        }
    }
    void pt(int j){
        while(j){
            cnt[val[j]]++;
            j = last[j];
        }
    }
};

int main()
{
    while(scanf("%d", &n), n){
        Trie *tr = new Trie();
        memset(cnt, 0, sizeof cnt);
        ms.clear();
        for (int i = 1; i <= n; i++){
            scanf("%s", moshi[i]);
            tr->insert(moshi[i], i);
        }
        tr->getFail();
        scanf("%s", wenben);
        tr->find(wenben);
        int mx = 0;
        for (int i = 1; i <= n; i++){
            if(cnt[i] > mx)
                mx = cnt[i];
        }
        printf("%d\n", mx);
        for (int i = 1; i <= n; i++){
            if(cnt[ms[string(moshi[i])]] == mx)
                printf("%s\n", moshi[i]);
        }
        delete tr;
    }
    return 0;
}

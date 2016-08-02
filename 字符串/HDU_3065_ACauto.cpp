#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

#define maxnode 50010
#define sigma_size 26

char bingdu[1010][50];
char web[2000010];
int cnt[1010];
int n;

struct Trie{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int last[maxnode];
    int f[maxnode];
    int sz;
    Trie(){
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset(val, 0, sizeof val);
        memset(last, 0, sizeof last);
        memset(f, 0, sizeof f);
    }

    int idx(char d){
        return d-'A';
    }

    void insert(char* s, int v){
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

    void find(char *T){
        int n = strlen(T);
        int j = 0;
        for (int i = 0; i < n; i++){
            int c = idx(T[i]);
            if(c < 0 || c > 25){
                j = 0;
                continue;
            }
            j = ch[j][c];
            if(val[j]) pt(j);
            else if(last[j]) pt(j);
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
    while(~scanf("%d", &n)){
        Trie *tr = new Trie();
        for (int i = 1; i <= n; i++){
            scanf("%s", bingdu[i]);
            tr->insert(bingdu[i], i);
        }
        tr->getFail();
        scanf("%s", web);
        memset(cnt, 0, sizeof cnt);
        tr->find(web);
        for (int i = 1; i <= n; i++){
            if(cnt[i] != 0){
                printf("%s: %d\n", bingdu[i], cnt[i]);
            }
        }
        delete tr;
    }
    return 0;
}

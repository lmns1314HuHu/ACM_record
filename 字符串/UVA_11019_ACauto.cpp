#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

#define maxnode 20000
#define sigma_size 26
int t, n, m, x, y;
int cnt[1010][1010];
char wenben[1010][1010];
char moshi[110];

struct Trie{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int f[maxnode];
    int last[maxnode];
    int next[maxnode];//next[i]存储的是编号为i的边的下一条边的边号是什么，用于处理相同的字符串
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
        if(val[u]){//如果有相同的串，用next存起来
            next[v] = val[u];
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
                last[u] = last[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
    void find(char* T, int wenbenhang){
        int n = strlen(T);
        int j = 0;
        for (int i = 0; i < n; i++){
            int c = idx(T[i]);
            j = ch[j][c];
            if(val[j]) pt(j, wenbenhang, i);
            else if(last[j]) pt(last[j], wenbenhang, i);
        }
    }
    void pt(int j, int wenbenhang, int wenbenlie){
        while(j){
            int qian = wenbenhang - val[j] + 1, hou = wenbenlie - x + 1;
            if(qian >= 1 && qian <= n && hou >= 0 && hou < m)
                cnt[qian][hou]++;
            int t = val[j];
            while(next[t]){//检查是否有相同的串
                t = next[t];
                qian = wenbenhang - t + 1;
                if(qian >= 1 && qian <= n)
                    cnt[qian][hou]++;
            }
            j = last[j];
        }
    }

};

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        Trie* tr = new Trie();
        for (int i = 1; i <= n; i++){
            scanf("%s", wenben[i]);
        }
        memset(cnt, 0, sizeof cnt);
        scanf("%d%d", &x, &y);
        for (int i = 1 ; i <= x; i++){
            scanf("%s", moshi);
            tr->insert(moshi, i);
        }
        tr->getFail();
        for(int i = 1; i <= n; i++){
            tr->find(wenben[i], i);
        }
        int res = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < m; j++){
                if(cnt[i][j] == x){
                    res ++;
                }
            }
        }
        printf("%d\n", res);
        delete tr;
    }
    return 0;
}

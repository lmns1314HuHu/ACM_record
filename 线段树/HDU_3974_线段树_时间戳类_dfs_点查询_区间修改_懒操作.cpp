#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
#define maxn 50010

int t, n, m, x, y;
char ch;
int lz[maxn<<2];

vector<int> grid[maxn];
int cnt, stt[maxn], ed[maxn];
bool visit[maxn];
void dfs(int u){//将每个人映射成一个区间，如果对人进行任务安排，就对线段树上的一段区间进行任务安排
    stt[u] = ++cnt;
    for (int i = 0; i < grid[u].size(); i++){
        dfs(grid[u][i]);
    }
    ed[u] = cnt;
}

void pushdown(int o){
    int lc=o<<1, rc=o<<1|1;
    if(lz[o] >= 0){
        lz[lc] = lz[rc] = lz[o];
        lz[o] = -1;
    }
}

int p;
int query(int o, int l, int r){//点查询
    int m = (l+r)>>1, lc=o<<1, rc=o<<1|1;
    if(r > l){
        if(lz[o] >= 0)
            return lz[o];
        if(p <= m) return query(lc, l, m);
        else return query(rc, m+1, r);
    }
    return lz[o];
}

int y1, y2, v;
void update(int o, int l, int r){//区间修改
    if(y1 <= l && r <= y2)
        lz[o] = v;
    else{
        pushdown(o);
        int m = (l+r)>>1, lc=o<<1, rc=o<<1|1;
        if(y1 <= m) update(lc, l, m);
        if(y2 > m) update(rc, m+1, r);
    }
}

int main()
{
    scanf("%d", &t);
    int w = 1;
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            grid[i].clear();
        memset(visit, 0, sizeof visit);
        for (int i = 0; i < n-1; i++){
            scanf("%d%d", &x, &y);
            grid[y].push_back(x);
            visit[x] = true;
        }
        cnt = 0;
        for (int i = 1; i <= n; i++){
            if(!visit[i])
                dfs(i);
        }
        printf("Case #%d:\n", w++);
        memset(lz, -1, sizeof lz);
        scanf("%d", &m);
        for (int i = 0; i < m; i++){
            while(1){
                ch = getchar();
                if(ch == 'C' || ch == 'T') break;
            }
            if(ch == 'C'){
                scanf("%d", &x);
                p = stt[x];
                printf("%d\n", query(1, 1, n));
            }
            else{
                scanf("%d%d", &x, &y);
                y1 = stt[x], y2 = ed[x], v = y;
                update(1, 1, n);
            }
        }
    }
    return 0;
}

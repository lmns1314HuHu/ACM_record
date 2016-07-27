#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define maxn 1010
#define inf 10000000
//带权、有向、有重边
vector< pair<int, int> >V[maxn];//将边正向存在vector中
int V2[maxn][maxn];//将边反向存在邻接矩阵中
int _h[maxn];//下届函数，将所有边反向，求边到中点的最短路作为评估下届
int n, m, a, b, c, s, t, k;
int visit[maxn];

struct node{//dijkstra中用到的节点
    int d, u;
    bool operator < (const node& no)const{
        return d > no.d;
    }
};

struct nd{//a_star中用到的节点
    int num, f, g, h;
    bool operator < (const nd& no) const{
        return f > no.f;
    }
};

priority_queue<nd> q2;//a_star中用到的队列

void dijkstra(int t){
    priority_queue<node> q;
    for (int i = 0; i < n; i++)
        _h[i] = inf;
    _h[t] = 0;
    memset(visit, 0, sizeof visit);
    q.push((node){0, t});
    while(!q.empty()){
        node no = q.top();
        q.pop();
        if(visit[no.u]) continue;
        visit[no.u] = true;
        for (int i = 1; i <= n; i++){
            if(V2[no.u][i] >= 10000000) continue;
            if(_h[i] > V2[no.u][i] + _h[no.u]){
                _h[i] = V2[no.u][i] + _h[no.u];
                q.push((node){_h[i], i});
            }
        }
    }
}

bool a_star(int s, int t, int k){
    while(q2.size())q2.pop();
    memset(visit, 0, sizeof visit);

    nd root, u, no;//初始化
    root.num = s;
    root.h = _h[s];
    root.g = 0;
    root.f = root.h + root.g;
    q2.push(root);
    int cnt = 0;

    while(!q2.empty()){
        u = q2.top();
        q2.pop();
        
        if(u.num == t){
            cnt++;
            if(cnt == k){//找到k短路，输出
                printf("%d\n", u.f);
                return true;
            }
        }
        visit[u.num]++;//对于每一个节点，出队！一定是出队，K次以上就不在入队了。因为是k短路，所以同一个节点一定不可能出队多于k次
        if(visit[u.num] > k) continue;
        for (int i = 0; i < V[u.num].size(); i++){
            int v = V[u.num][i].first, len = V[u.num][i].second;
            no.num = v;
            no.h = _h[no.num];
            no.g = u.g + len;
            no.f = no.g + no.h;
            q2.push(no);
        }

    }
    return false;

}

int main()
{
    while(~scanf("%d%d", &n, &m)){
        for (int i = 0; i <= n; i++){
            V[i].clear();
            for (int j = 0; j <= n; j++){
                V2[i][j] = inf;
            }
        }
        for (int i = 0; i < m; i++){
            scanf("%d%d%d", &a, &b, &c);
            V[a].push_back(make_pair(b, c));
            if(c < V2[b][a]){//反向建图，去重边
                V2[b][a] = c;
            }
        }
        scanf("%d%d%d", &s, &t, &k);
        if(s == t) k++;
        dijkstra(t);
        if(!a_star(s, t, k)){
            printf("-1\n");
        }
    }
    return 0;
}

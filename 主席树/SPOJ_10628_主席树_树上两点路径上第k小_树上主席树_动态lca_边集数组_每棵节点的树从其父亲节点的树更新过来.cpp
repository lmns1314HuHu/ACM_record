//本题是让求树上两点路径之间的第k大，树上主席树+动态lca
//要用边集数组来存边，用vector可能会TLE
//本题的思路是每个节点对应的线段树是从其父亲节点的线段树修改过来的，这样每个节点的线段树的结果，都是到根节点的路径上所有点的结果
//在进行查询的时候，只需要两个节点都对他们的lca节点做差就是u，v路径上所有点的线段树的结果。
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

#define maxn 100005
#define maxm 100005

int n, m;
int u, v;
int x, y, z;
int val[maxn], valc[maxn];

int len;//离散后的长度
int tot, trcnt;
int tr[maxn];
int lc[maxn*30], rc[maxn*30], sum[maxn*30];

//---------------edge array----------------
struct Edge{
    int to, next;
}edge[maxn*2];
int totedge, head[maxn];

void init_edge(){
    totedge = 0;
    memset(head, -1, sizeof head);
}
void add_edge(int  u, int v){//无向图要加两条边
    edge[totedge].to = v;
    edge[totedge].next = head[u];
    head[u] = totedge++;
}
//-----------------------------------------

//-----------presistent seg tree--------------
void init_segtree(){//建树之前的初始化
    tot = trcnt = 0;
    memcpy(valc, val, sizeof val);
    sort(valc, valc+n);
    len = unique(valc, valc+n)-valc;
}
int build_segtree(int l, int r){//建树操作
    int root = tot++;
    sum[root] = 0;
    if(l != r){
        int mid = (l+r)>>1;
        lc[root] = build_segtree(l, mid);
        rc[root] = build_segtree(mid+1, r);
    }
    return root;
}
int update_segtree(int Lroot, int l, int r, int pos){//主席树正常的更新操作，根据Lroot创建一个新的树，与Lroot公用节点
    int newroot = tot++;
    sum[newroot] = sum[Lroot] + 1;
    if(l != r){
        int mid = (l+r)>>1;
        if(pos <= mid){
            lc[newroot] = update_segtree(lc[Lroot], l, mid, pos);
            rc[newroot] = rc[Lroot];
        }
        else{
            lc[newroot] = lc[Lroot];
            rc[newroot] = update_segtree(rc[Lroot], mid+1, r, pos);
        }
    }
    return newroot;
}
void dfs_update(int child, int fa){//主席树的dfs更新操作，用子节点的树通过父节点的树来建，与父节点的树公用节点。
    int hash = lower_bound(valc, valc+len, val[child-1])-valc;//这样的话，每个节点存储的是从根节点到当前节点的修改操作后的结果。查询操作好维护。
    tr[child] = update_segtree(tr[fa], 0, len-1, hash);
    for (int i = head[child]; i != -1; i=edge[i].next){
        int to = edge[i].to;
        if(to == fa) continue;
        dfs_update(to, child);
    }
}
int query_segtree(int one, int two, int father, int l, int r, int rk, int fatherhash){//查询u，v路径上的第k小。
    int mid = (l+r)>>1;
    if(l == r) return l;
    int tmp = sum[lc[one]] - sum[lc[father]] + sum[lc[two]] - sum[lc[father]];//u，v路径上不包括公共祖先的点的线段树在左子树上的结果。与静态区间第k大思路相仿。
    if(fatherhash >= l && fatherhash <= mid) tmp++;//看公共祖先这个点的哈希值是否应该包含在线段树的左树上，是就加上
    if(tmp >= rk) return query_segtree(lc[one], lc[two], lc[father], l, mid, rk, fatherhash);//如果在排名在左子树上的点的数量大于等于k，左子上寻找
    else return query_segtree(rc[one], rc[two], rc[father], mid+1, r, rk-tmp, fatherhash);//否则就在右子上寻找
}
//------------------------------------------------

//----------------lca dynamic------------------kuangbin模板
int rmq[2*maxn];
struct ST{
    int mm[2*maxn];
    int dp[2*maxn][20];
    void init(int n){
        mm[0] = -1;
        for (int i = 1; i <= n; i++){
            mm[i] = ((i&(i-1)) == 0) ? mm[i-1]+1 : mm[i-1];
            dp[i][0] = i;
        }
        for (int j = 1; j <= mm[n]; j++)
            for (int i = 1; i + (1<<j)-1 <= n; i++)
                dp[i][j] = rmq[dp[i][j-1]] < rmq[dp[i+(1<<(j-1))][j-1]] ? dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
    }
    int query(int a, int b){
        if(a > b) swap(a, b);
        int k = mm[b-a+1];
        return rmq[dp[a][k]] <= rmq[dp[b-(1<<k)+1][k]] ? dp[a][k] : dp[b-(1<<k)+1][k];
    }
};
int F[maxn*2];//欧拉序列
int P[maxn];
int cnt;
ST st;
void dfs_lca(int u, int pre, int dep){//求三个序列
    F[++cnt] = u;
    rmq[cnt] = dep;
    P[u] = cnt;
    for (int i = head[u]; i != -1; i = edge[i].next){
        int v = edge[i].to;
        if(v == pre) continue;
        dfs_lca(v, u, dep+1);
        F[++cnt] = u;
        rmq[cnt] = dep;
    }
}
void init_lca(int root, int node_num){
    cnt = 0;
    dfs_lca(root, root, 0);
    st.init(2*node_num-1);
}
int query_lca(int u, int v){
    return F[st.query(P[u],P[v])];
}
//--------------------------------------------

int main()
{
    while(~scanf("%d%d", &n, &m)){
        for (int i = 0; i < n; i++) scanf("%d", &val[i]);

        init_segtree();//建树
        tr[0] = build_segtree(0, len-1);

        init_edge();//读图
        for (int i = 0; i < n-1; i++){
            scanf("%d%d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }

        dfs_update(1, 1);//继续建主席树

        init_lca(1, n);//lca询问初始化
        while(m--){
            scanf("%d%d%d", &x, &y, &z);
            int father = query_lca(x, y);
            int fatherhash = lower_bound(valc, valc+len, val[father-1])-valc;
            printf("%d\n", valc[query_segtree(tr[x], tr[y], tr[father], 0, len-1, z, fatherhash)]);
        }
    }
    return 0;
}

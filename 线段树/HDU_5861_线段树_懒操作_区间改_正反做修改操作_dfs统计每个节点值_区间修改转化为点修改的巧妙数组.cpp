//本题要对所有询问正着修改一次，然后得到的是每条路最后一次使用的时间，然后在将所有修改倒着来一次，得到的是每条路第一次使用的时间
//如果想要正着得到每条路第一次修改的时间是有bug的。因为如果想要正着查询时候找到第一次修改的时间就需要对每一条路在没有被用的时候更新，
//一但该路被用过，就不能更新，这样的话。必须每次修改操作都修改到叶节点才能保证不出问题，因为如果一但想要在某个区间放懒操作时，
//无法得知改区间的子区间是否已经有懒操作了，所以可能会错误的将某个已经有懒操作的节点的懒操作覆盖掉，这样无法保证一个节点有懒操作，
//就不在更新的前提。无法保证节点的懒操作是第一次修改的懒操作值，相反的，如果，每次操作都更新的话，那么最后得到的一定是这个节点最后一次使用的时间
//然后想要找到这个节点第一次使用的时间就将所有的操作倒着在来一遍就好了。
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

#define maxn 200010

int n, m;
int lz[maxn<<2];
int cost[maxn];//每条路的花费
int stt[maxn], ed[maxn];//每条路的最早开启时间，最晚开启时间
int tot[maxn];//总花费

vector< pair<int, int> > qry;//保存询问，用来倒着来一边询问

void build(){
    memset(lz, -1, sizeof lz);
}

void pushdown(int o){
    if(lz[o] != -1){
        int lc=o<<1, rc=o<<1|1;
        lz[lc] = lz[rc] = lz[o];
        lz[o] = -1;
    }
}

int y1, y2, v;
void update(int o, int l, int r){
    if(y1 <= l && r <= y2)
        lz[o] = v;
    else{
        pushdown(o);
        int mid = (l+r)>>1, lc=o<<1, rc=o<<1|1;
        if(y1 <= mid) update(lc, l, mid);
        if(y2 > mid) update(rc, mid+1, r);
    }
}

void dfs1(int o, int l, int r){//对线段树进行dfs得到每条路的最后使用时间。
    if(lz[o] >= 0 || l == r){//如果一个节点有懒操作那么，就把该节点对应区间内所有的路的开启时间都更新。
        for (int i = l-1; i < r; i++)
            ed[i] = lz[o];
        return;
    }
    int mid=(l+r)>>1, lc=o<<1, rc=o<<1|1;
    dfs1(lc, l, mid);
    dfs1(rc, mid+1, r);
}

void dfs2(int o, int l, int r){//得到每条路最初使用的时间
    if(lz[o] >= 0 || l == r){
        for (int i = l-1; i < r; i++)
            stt[i] = lz[o];
        return;
    }
    int mid = (l+r)>>1, lc=o<<1, rc=o<<1|1;
    dfs2(lc, l, mid);
    dfs2(rc, mid+1, r);
}

int main()
{
    while(~scanf("%d%d", &n, &m)){
        for (int i = 0; i < n-1; i++){
            scanf("%d", &cost[i]);
        }
        qry.clear();
        memset(tot, 0, sizeof tot);

        build();
        for (int i = 1; i <= m; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            if(a > b) swap(a, b);//一定要注意这个！！神坑！
            qry.push_back(make_pair(a, b));//保存询问
            a--, b-=2;//由于询问是从a到b村庄，所以途中经历了b-a+1条路，所以要这么减一下
            y1 = a+1, y2 = b+1, v = i;
            update(1, 1, n-1);
        }
        dfs1(1, 1, n-1);//正着修改一次之后得到最后一次使用的时间

        build();
        for (int i = qry.size()-1; i >= 0; i--){
            int a = qry[i].first, b = qry[i].second;
            a--, b-= 2;
            y1 = a+1, y2 = b+1, v = i+1;
            update(1, 1, n-1);
        }
        dfs2(1, 1, n-1);//反着修改一次之后得到最初的使用时间

        for (int i = 0; i < n-1; i++){//tot数组存的信息很巧妙。设第i天的花费是bi，那么tot数组存的是B1,B2-B1,B3-B2,B4-B3,...,Bi-Bi-1,...所以如果想求第i天的花费的话就是前i项的前缀和
            int qian = stt[i]-1, hou = ed[i]-1;
            tot[qian] += cost[i];//根据tot数组的含义，对每一个路进行遍历，更新从路最初使用时间到最后使用时间的tot数组即只需要更新两个端点就能够保证tot数组的含义
            tot[hou+1] -= cost[i];
        }
        ll res = 0;
        for (int i = 0; i < m; i++){
            res += tot[i];
            printf("%lld\n", res);//输出第i天的花费
        }
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

#define maxn 100010
#define maxm 50010

int n, m;
int val[maxn], valc[maxn];

int tr[maxn];
int tot, trcnt, len;
int sum[maxn*30], lc[maxn*30], rc[maxn*30];

void init(){
    tot = trcnt = 0;
    memcpy(valc, val, sizeof val);
    sort(valc, valc + n);
    len = unique(valc, valc+n)-valc;
}

int build(int l, int r){
    int root = tot++;
    sum[root] = 0;
    if(l != r){
        int mid = (l+r)>>1;
        lc[root] = build(l, mid);
        rc[root] = build(mid+1, r);
    }
    return root;
}

int update(int Lroot, int l, int r, int val){
    int root = tot++;
    sum[root] = sum[Lroot] + 1;
    if(l != r){
        int mid = (l+r)>>1;
        if(val <= mid){
            lc[root] = update(lc[Lroot], l, mid, val);
            rc[root] = rc[Lroot];
        }
        else{
            lc[root] = lc[Lroot];
            rc[root] = update(rc[Lroot], mid+1, r, val);
        }
    }
    return root;
}

int query(int Lroot, int Rroot, int l, int r, int rk){
    if(l == r) return l;
    int tmp = sum[lc[Rroot]] - sum[lc[Lroot]], mid=(l+r)>>1;
    if(tmp >= rk) return query(lc[Lroot], lc[Rroot], l, mid, rk);
    else return query(rc[Lroot], rc[Rroot], mid+1, r, rk-tmp);
}

int main()
{
    while(~scanf("%d%d", &n, &m)){
        for (int i = 0; i < n; i++)
            scanf("%d", &val[i]);
        init();
        tr[0] = build(0, len-1);
        for (int i = 0; i < n; i++){
            int hash = lower_bound(valc, valc+len, val[i]) - valc;
            tr[i+1] = update(tr[i], 0, len-1, hash);
        }
        while(m--){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if(a > b) swap(a, b);
            printf("%d\n", valc[query(tr[a-1], tr[b], 0, len-1, c)]);
        }
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
#define maxn 1000010
int n, m, q, x, y;
ll a[maxn];

struct node{
    int l, r;
    ll sum;//存储区间和
    bool all;//存储区间内是否都是1
}tr[maxn*4];

void build(int d, int l, int r){
    tr[d].l = l, tr[d].r = r;
    tr[d].all = false;
    if(l == r){
        tr[d].sum = a[l];
        if(tr[d].sum == 1) 
            tr[d].all = true;
        return;
    }

    int mid=(l+r)>>1, lc=d<<1, rc=d<<1|1;
    build(lc, l, mid);
    build(rc, mid+1, r);

    tr[d].all = (tr[lc].all && tr[rc].all);
    tr[d].sum = tr[lc].sum + tr[rc].sum;
}

void update(int d, int l, int r){//每次更新都更新到最终的叶子节点，或是到一个区间已经都是1
    if(tr[d].all) return;
    if(tr[d].l == tr[d].r){
        tr[d].sum = floor(sqrt(tr[d].sum));
        if(tr[d].sum == 1)
            tr[d].all = true;
        return;
    }

    int mid=(tr[d].l+tr[d].r)>>1, lc=d<<1, rc=d<<1|1;

    if(r <= mid) update(lc, l, r);
    else if(l > mid) update(rc, l, r);
    else {
        update(lc, l, mid);
        update(rc, mid+1, r);
    }

    tr[d].all = (tr[lc].all && tr[rc].all);
    tr[d].sum = tr[lc].sum + tr[rc].sum;

}

ll query(int d, int l, int r){
    if(tr[d].l == l && tr[d].r == r)
        return tr[d].sum;

    int mid = (tr[d].l+tr[d].r)>>1, lc=d<<1, rc=d<<1|1;

    if(r <= mid) return query(lc, l, r);
    else if (l > mid) return query(rc, l, r);
    else return query(lc, l, mid) + query(rc, mid+1, r);
}

int main()
{
    int w = 1;
    while(~scanf("%d", &n)){
        for (int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
        }
        printf("Case #%d:\n", w++);
        build(1, 1, n);

        scanf("%d", &m);
        while(m--){
            scanf("%d%d%d", &q, &x, &y);
            if(x > y)swap(x, y);//x有可能大于y！神坑
            if(q == 0){
                update(1, x, y);
            }
            else if(q == 1){
                ll res = query(1, x, y);
                printf("%lld\n", res);
            }
        }
        printf("\n");
    }
    return 0;
}

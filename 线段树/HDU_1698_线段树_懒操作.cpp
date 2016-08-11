#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 100010
int t, n, q, x, y, z;

int b[maxn];
struct node{
    int l, r, sum, lz;
}tr[maxn*4];

void build(int d, int l, int r){
    tr[d].l = l, tr[d].r = r;
    tr[d].lz = 0;
    if(l == r){
        tr[d].sum = 1;
        return ;
    }
    int mid = (l+r)/2;
    int lc = d*2;
    int rc = d*2+1;
    build(lc, l, mid);
    build(rc, mid+1, r);
    tr[d].sum = tr[lc].sum + tr[rc].sum;
}

void update(int d, int l, int r, int k){
    if(tr[d].l == l && tr[d].r == r){
        tr[d].lz = k;
        tr[d].sum = (r-l+1)*tr[d].lz;
        return;
    }
    int mid = (tr[d].l + tr[d].r) / 2;
    int lc = d*2;
    int rc = d*2+1;
    //lazy push down
    if(tr[d].lz != 0){
        tr[lc].lz = tr[d].lz;
        tr[lc].sum = (tr[lc].r - tr[lc].l + 1) * tr[lc].lz;
        tr[rc].lz = tr[d].lz;
        tr[rc].sum = (tr[rc].r - tr[rc].l + 1) * tr[rc].lz;
        tr[d].lz = 0;
    }
    //go to child
    if(r <= mid) update(lc, l, r, k);
    else if(l > mid) update(rc, l, r, k);
    else{
        update(lc, l, mid, k);
        update(rc, mid+1, r, k);
    }
    tr[d].sum = tr[lc].sum + tr[rc].sum;
}

int main()
{
    scanf("%d", &t);
    for(int w = 1; w <= t; w++){
        scanf("%d%d", &n, &q);
        build(1, 1, n);
        for (int i = 0; i < q; i++){
            scanf("%d%d%d", &x, &y, &z);
            update(1, x, y, z);
//            printf("%d\n", tr[1].sum);
        }
        printf("Case %d: The total value of the hook is %d.\n", w, tr[1].sum);
    }
    return 0;
}

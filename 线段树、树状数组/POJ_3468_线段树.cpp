#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 100010
int n, q;
char ch;
int x, y, z;
int b[maxn];

struct node{
    int l, r;
    long long sum, lz;
}tr[maxn*4];

void build(int d, int l, int r){
    tr[d].l = l, tr[d].r = r;
    tr[d].lz = 0;
    if(l == r){
        tr[d].sum = b[l];
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
        tr[d].lz += k;
        return;
    }
    int mid = (tr[d].l + tr[d].r) / 2;
    int lc = d*2;
    int rc = d*2+1;
    //lazy push down
    if(tr[d].lz != 0){
        tr[lc].lz += tr[d].lz;
        tr[rc].lz += tr[d].lz;
        tr[d].sum += (long long)((tr[d].r-tr[d].l+1) * tr[d].lz);
        tr[d].lz = 0;
    }
    //go to child
    if(r <= mid) update(lc, l, r, k);
    else if(l > mid) update(rc, l, r, k);
    else{
        update(lc, l, mid, k);
        update(rc, mid+1, r, k);
    }
    tr[d].sum = (long long)(tr[lc].sum + tr[rc].sum + (tr[lc].r-tr[lc].l+1)*tr[lc].lz + (tr[rc].r-tr[rc].l+1)*tr[rc].lz);
}

long long query(int d, int l, int r){
    if(tr[d].l == l && tr[d].r == r){
        return (long long)(tr[d].sum + (tr[d].r-tr[d].l+1)*tr[d].lz);
    }
    int mid = (tr[d].l + tr[d].r) / 2;
    int lc = 2*d;
    int rc = 2*d+1;

    //lazy push down
    if(tr[d].lz != 0){
        tr[lc].lz += tr[d].lz;
        tr[rc].lz += tr[d].lz;
        tr[d].sum += (long long)((tr[d].r-tr[d].l+1) * tr[d].lz);
        tr[d].lz = 0;
    }
    //go to child
    if(r <= mid) return query(lc, l, r);
    else if(l > mid) return query(rc, l, r);
    else return query(lc, l, mid) + query(rc, mid+1, r);
}

int main()
{
    while(~scanf("%d%d", &n, &q)){
        for (int i = 1; i <= n; i++){
            scanf("%d", &b[i]);
        }
        build(1, 1, n);
        for (int i = 0; i < q; i++){
            getchar();
            scanf("%c %d %d", &ch, &x, &y);
            if(ch == 'C'){
                scanf("%d", &z);
                update(1, x, y, z);
            }
            else if(ch == 'Q'){
                printf("%lld\n", query(1,x,y));
            }
        }
    }
    return 0;
}

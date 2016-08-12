#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

#define maxn 1000010

int n, q, x, y, k;
ll b[maxn];//如果改成int会TLE
struct node{
    int l, r;
    bool allone;
    ll sum;
}tr[maxn*4];

void build(int d, int l, int r){
    tr[d].l = l, tr[d].r = r;
    tr[d].allone = false;
    if(l == r){
        tr[d].sum = b[l];
        if(tr[d].sum == 1) tr[d].allone = true;
        return;
    }
    int mid = (l+r)>>1, lc=d<<1, rc=d<<1|1;
    build(lc, l, mid);
    build(rc, mid+1, r);

    tr[d].allone = (tr[lc].allone && tr[rc].allone);
    tr[d].sum = tr[lc].sum + tr[rc].sum;
}

void update(int d, int l, int r){
    if(tr[d].allone) return;
    if(tr[d].l == tr[d].r){
        tr[d].sum = sqrt(tr[d].sum);
        if(tr[d].sum == 1)tr[d].allone = true;
        return;
    }
    int mid = (tr[d].l+tr[d].r)>>1, lc=d<<1, rc=d<<1|1;
    if(r <= mid) update(lc, l, r);
    else if(l > mid) update(rc, l, r);
    else{
        update(lc, l, mid);
        update(rc, mid+1, r);
    }
    tr[d].allone = (tr[lc].allone && tr[rc].allone);
    tr[d].sum = tr[lc].sum + tr[rc].sum;
}

ll query(int d, int l, int r){
    if(tr[d].allone) return (long long)(r-l+1);
    if(tr[d].l == l && tr[d].r == r)
        return tr[d].sum;
    int mid = (tr[d].l + tr[d].r)>>1, lc=d<<1, rc=d<<1|1;
    if(r <= mid) return query(lc, l, r);
    else if (l > mid) return query(rc, l, r);
    else return query(lc, l, mid) + query(rc, mid+1, r);
}

int main()
{
    int w = 1;
    while(~scanf("%d", &n)){
        for (int i = 1; i <= n; i++){
            scanf("%lld", &b[i]);
        }
        printf("Case #%d:\n", w++);
        build(1, 1, n);
        //for (int i = 0; i < 10; i++){
            //cout << endl;
            //cout << "l=" << tr[i].l << "/ r="<< tr[i].r << endl;
            //cout << "sum=" << tr[i].sum << endl;
            //cout << "allone" << tr[i].allone << endl;
            //cout << endl;
        //}
        scanf("%d", &q);
        for (int i = 0; i < q; i++){
            scanf("%d%d%d", &k, &x, &y);
            if(x > y) swap(x, y);
            if(k == 0) update(1, x, y);
            else{
                ll res = query(1, x, y);
                printf("%lld\n", res);
            }
        }
        printf("\n");
    }
    return 0;
}

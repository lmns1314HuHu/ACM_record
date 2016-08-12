#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

#define maxn 50010

int b[maxn];
int n, q;
int x, y;
struct node{
    int l, r, mx, mi;
}tr[maxn*4];

void build(int d, int l, int r){
    tr[d].l = l, tr[d].r = r;
    if(l == r){
        tr[d].mx = b[l];
        tr[d].mi = b[l];
        return;
    }
    int mid = (l+r)>>1, lc = d<<1, rc = d<<1|1;
    build(lc, l, mid);
    build(rc, mid+1, r);
    tr[d].mx = max(tr[lc].mx, tr[rc].mx);
    tr[d].mi = min(tr[lc].mi, tr[rc].mi);
}

pair<int, int> query(int d, int l, int r){
    if(tr[d].l == l && tr[d].r == r){
        return make_pair(tr[d].mx, tr[d].mi);
    }
    int mid = (tr[d].l + tr[d].r)>>1, lc=d<<1, rc=d<<1|1;
    if(r <= mid) return query(lc, l, r);
    else if(l > mid) return query(rc, l, r);
    else{
        pair<int, int> tmp = query(lc, l, mid);
        pair<int, int> tmp1 = query(rc, mid+1, r);
        int qian = max(tmp.first, tmp1.first);
        int hou = min(tmp.second, tmp1.second);
        return make_pair(qian,hou);
    }
}

int main()
{
    while(~scanf("%d%d", &n, &q)){
        for (int i = 1; i <= n; i++){
            scanf("%d", &b[i]);
        }
        build(1, 1, n);
        for (int i = 0; i < q; i++){
            scanf("%d%d", &x, &y);
            pair<int, int> res = query(1, x, y);
            printf("%d\n", res.first - res.second);
        }
    }
    return 0;
}

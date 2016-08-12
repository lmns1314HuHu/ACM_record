#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 200100

struct node{
    int l, r, mx;
}tr[maxn*4];

int n, m;
int b[maxn];
char ch;
int u, v;

void build(int d, int l, int r){
    tr[d].l = l;
    tr[d].r = r;
    if(l==r){tr[d].mx = b[l]; return;}
    int mid = (l+r) / 2;
    int lc = d*2;
    int rc = d*2+1;
    build(lc, l, mid);
    build(rc, mid+1, r);
    tr[d].mx = max(tr[lc].mx, tr[rc].mx);
}

void update(int d, int pos, int v){
    if(tr[d].l == tr[d].r && tr[d].l == pos){
        tr[d].mx = v;
        return;
    }
    int mid = (tr[d].l + tr[d].r)/2;
    int lc = d*2;
    int rc = d*2+1;
    if(pos <= mid) update(lc, pos, v);
    else update(rc, pos, v);
    tr[d].mx = max(tr[lc].mx, tr[rc].mx);
}

int query(int d, int l, int r){
    if(tr[d].l == l && tr[d].r == r){
        return tr[d].mx;
    }
    int mid = (tr[d].l + tr[d].r)/2;
    int lc = d*2;
    int rc = d*2+1;
    if (r <= mid) return query(lc, l, r);
    else if(l > mid) return query(rc, l, r);
    else return max(query(lc, l, mid), query(rc, mid +1, r));
}

int main()
{
    while(~scanf("%d%d", &n, &m)){
        for (int i = 1; i <= n; i++){
            scanf("%d", &b[i]);
        }
        build(1, 1, n);
        for (int i = 0; i < m; i++){
            getchar();
            scanf("%c %d %d", &ch, &u, &v);
            if(ch == 'U'){
                update(1, u, v);
            }
            else if(ch == 'Q'){
                printf("%d\n", query(1, u, v));
            }
        }
    }
    return 0;
}

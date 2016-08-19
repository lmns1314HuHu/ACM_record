#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
#define maxn 100001

int n, m;
int L, R, d;

int v[maxn], t[maxn];
int c[maxn*30], ls[maxn*30], rs[maxn*30];
int Ro[maxn], tot, Rocnt;

void init(){
    tot = 0;
    memcpy(t, v, sizeof v);
    sort(t, t+n);
}

int build(int l, int r){
    int root = tot++, mid = (l+r)>>1;
    c[root] = 0;
    if(l < r){
		ls[root] = build(l, mid);
		rs[root] = build(mid+1, r);
    }
	return root;
}

int update(int l, int r, int val, int root){
    int nr = tot++, mid = (l+r)>>1;
    c[nr] = c[root] + 1;
    if(l != r){
        if(val <= mid){
			ls[nr] = update(l, mid, val, ls[root]);
            rs[nr] = rs[root];
        }
        else {
            ls[nr] = ls[root];
            rs[nr] = update(mid+1, r, val, rs[root]);
        }
    }
	return nr;
}

int query(int Rroot, int Lroot, int d, int l, int r){
    int mid = (l+r)>>1;
    if(l == r) return l;
	int sum = c[ls[Rroot]] - c[ls[Lroot]];
    if(d <= sum) return query(ls[Rroot], ls[Lroot], d, l, mid);
    else return query(rs[Rroot], rs[Lroot], d-sum, mid+1, r);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while(tt--){
        scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%d", &v[i]);
		init();
		int r = unique(t, t + n) - t;
		Ro[0] = build(0, r-1);
		
		for (int i = 0; i < n; i++){
			Ro[i+1] = update(0, r-1, lower_bound(t, t+r, v[i])-t, Ro[i]);
		}
		for (int i = 0; i < m; i++){
			scanf("%d%d%d", &L, &R, &d);
			printf("%d\n", t[query(Ro[R], Ro[L-1], d, 0, r-1)]);
		}
	}
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n, t, l, r;
bool visit[10010];
int res;

struct tree{
	int l, r, lz;
}tr[20010*4];

struct node{
	int x, num;
}s[20010];

struct seg{
	int l, r, num;
}seq[10010];

void build(int d, int l, int r){
	tr[d].l = l, tr[d].r = r;
	tr[d].lz = 0;
	if(l == r){
		return ;
	}
	int mid = (l+r)>>1, lc=d<<1, rc=d<<1|1;
	build(lc, l, mid);
	build(rc, mid+1, r);
}

void add(int d, int l, int r, int k){
	if(tr[d].l == l && tr[d].r == r){
		tr[d].lz = k;
		return;
	}

	int mid=(tr[d].l + tr[d].r)>>1, lc=d<<1, rc=d<<1|1;
	
	//pushdown
	if(tr[d].lz != 0){
		tr[lc].lz = tr[d].lz;
		tr[rc].lz = tr[d].lz;
		tr[d].lz = 0;
	}
	
	//go to child
	if(r <= mid){
		add(lc, l, r, k);
	}
	else if(l > mid){
		add(rc, l, r, k);
	}
	else{
		add(lc, l, mid, k);
		add(rc, mid+1, r, k);
	}
	
}

void query(int d, int l, int r){
	if(tr[d].lz != 0){
		if(!visit[tr[d].lz]){
			visit[tr[d].lz] = true;
			res++;
		}
		return;
	}
	
	if(tr[d].l == tr[d].r)
		return;
		
	int mid = (tr[d].l+tr[d].r)>>1, lc=d<<1, rc=d<<1|1;
		
	if(r <= mid){
		query(lc, l, r);
	}
	else if(l > mid){
		query(rc, l, r);
	}
	else{
		query(lc, l, mid);
		query(rc, mid+1, r);
	}
}

bool cmp(node no1, node no2){
	if(no1.x != no2.x){
		return no1.x < no2.x;
	}
	return no1.num < no2.num;
}

int main()
{
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(visit, 0, sizeof visit);
		res = 0;
		for (int i = 0; i < n; i++){
			scanf("%d%d", &l, &r);
			s[i<<1].x = l;
			s[i<<1].num = -1*(i+1);
			s[i<<1|1].x = r;
			s[i<<1|1].num = (i+1);
		}
		sort(s, s+2*n, cmp);
		int cnt = 1, rem = s[0].x;
		if(s[0].num < 0){
			seq[-1*s[0].num].l = cnt;
		}
		else{
			seq[s[0].num].r = cnt;
		}
		for (int i = 1; i < 2*n; i++){
			if(s[i].x != rem){
				rem = s[i].x;
				cnt++;
			}
			if(s[i].num < 0){
				seq[-1*s[i].num].l = cnt;
			}
			else{
				seq[s[i].num].r = cnt;
			}
		}
		
		build(1, 1, cnt);
		for (int i = 1; i <= n; i++){
			add(1, seq[i].l, seq[i].r, i);
		}
		query(1, 1, cnt);
		printf("%d\n", res);
	}
	return 0;
}
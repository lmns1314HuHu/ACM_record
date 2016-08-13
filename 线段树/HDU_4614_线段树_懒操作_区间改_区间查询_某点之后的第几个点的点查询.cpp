#include <iostream>
#include <cstdio>         
#include <cstring>        
#include <algorithm>      
#include <queue>          
#include <vector>         

using namespace std;
typedef long long ll;

#define maxn 50010
int sum[maxn<<2];//维护区间的1的总和
int lz[maxn<<2];//懒操作（-1为无，0为清空懒操作，1为放花懒操作）
int fir[maxn<<2];//区间内第一个空花瓶的位置（-1为区间内没有空花瓶）
int lst[maxn<<2];//区间内最后一个空花瓶的位置（-1为区间内没有空花瓶）
int t, n, m;
int k, a, b;

void maintain(int o, int l, int r){
    int lc=o<<1, rc=o<<1|1;
    sum[o] = sum[lc] + sum[rc];
	fir[o] = fir[lc];
	lst[o] = lst[rc];
	if(fir[lc] == -1)
		fir[o] = fir[rc];
	if(lst[rc] == -1)
		lst[o] = lst[lc];
}

void build(int o, int l, int r){
	int mid = (l+r)>>1, lc=o<<1, rc=o<<1|1;
	sum[o] = 0;
	lz[o] = -1;
	if(l == r){
		fir[o] = l;
		lst[o] = l;
	}
	else{
		build(lc, l, mid);
		build(rc, mid+1, r);
		maintain(o, l, r);
	}
}

void pushdown(int o, int l, int r){
    int mid=(l+r)>>1, lc=o<<1, rc=o<<1|1;
    if(lz[o] >= 0){
        lz[lc] = lz[o];
        sum[lc] = (mid-l+1)*lz[o];
        lz[rc] = lz[o];
        sum[rc] = (r-mid)*lz[o];
		if(lz[o] == 0){
			fir[lc] = l, fir[rc] = mid+1;
			lst[lc] = mid, lst[rc] = r;
		}
		else if(lz[o] == 1){
			fir[lc] = fir[rc] = lst[lc] = lst[rc] = -1;
		}
        lz[o] = -1;
    }
}

int y1, y2, p;
void update(int o, int l, int r){//整体更改区间的值，赋1，或置0
    int mid=(l+r)>>1, lc=o<<1, rc=o<<1|1;
    if(y1 <= l && y2 >= r){//该区间被完全包含在要修改的区间内，懒操作。
        lz[o] = p;
        sum[o] = (r-l+1)*p;
		if(p == 0)
			fir[o] = l, lst[o] = r;
		else if(p == 1)
			fir[o] = lst[o] = -1;
    }
    else{
        pushdown(o, l, r);
        if(y1 <= mid) update(lc, l, mid);
        if(y2 > mid) update(rc, mid+1, r);
        maintain(o, l, r);
    }
}

int query_sum(int o, int l, int r){//求区间的和，一共有多少非空的花瓶
    int mid=(l+r)>>1, lc=o<<1, rc=o<<1|1;
    int ans = 0;
    if(y1 <= l && y2 >= r){
        return sum[o];
    }
    else{
        pushdown(o, l, r);
        if(y1 <= mid) ans = ans + query_sum(lc, l, mid);
        if(y2 > mid) ans = ans + query_sum(rc, mid+1, r);
    }
    return ans;
}


int query_fir(int o, int l, int r){//找p位置之后的第一个空花瓶出现的位置，找不到返回-1
	int mid=(l+r)>>1, lc=o<<1, rc=o<<1|1;
	int res = -1;
	if(fir[o] >= p || l == r || fir[o] == -1)//当前区间的第一个空花瓶出现的位置在p位置之后 或是 到了叶子节点 或是 当前区间没有空花瓶了
		return fir[o];
	else{//没到叶子节点 并且 区间内有花瓶 并且第一个出现的花瓶在p之前
		pushdown(o, l, r);
		if(p <= mid) res = query_fir(lc, l, mid);//询问左区间
		if(res < p || p > mid){//如果左区间内没有找到 或是 p点在 右子区间
			res = query_fir(rc, mid+1, r);
		}
		return res;//返回p之后第一个空花瓶的位置
	}
}

int query_lst(int o, int l, int r, int& rk){//找p位置之后第rk个空花瓶的位置，如果不够rk个，返回之后那个空花瓶位置
	int mid=(l+r)>>1, lc=o<<1, rc=o<<1|1;
	int res = -1, res2 = -1;
	if(sum[o] >= r-l+1 || r == l || (l >= p && r-l+1-sum[o] <= rk)){//如果当前区间没有空花瓶了 或是 到了叶子节点 或是当前区间左端点在p的右边并且区间内空花瓶数量小于rk个
		rk -= (r-l+1-sum[o]);//因为 需要通过rk来返回给上层，找完该区间的花瓶之后，还应该在后续区间找几个空花瓶。所以 l>=p时，可以直接知道区间内的空花瓶都应该包含在内。
		return lst[o];//而l<p的区间只能一直找到叶子节点，才能知道该区间到底有几个空花瓶在p之后，才能方便重新计算rk值
	}
	else{
		pushdown(o, l, r);
		bool flag = false;//一个标记，标记是否要继续在之后的区间找空花瓶
		if(p <= mid){
			res = query_lst(lc, l, mid, rk);
			if(rk > 0) flag = true;//没找到足够的空花瓶，还需要继续找
		}
		if(flag || p > mid) res2 = query_lst(rc, mid+1, r, rk);//如果之前的空花瓶没找够 或者 p点在右子区间
		if(res2 > res) res = res2;//为了防止res2是-1的情况
		return res;
	}
}

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        build(1, 1, n);
        for (int i = 0; i < m; i++){
            scanf("%d%d%d", &k, &a, &b);
            if(k == 1){
                a++;//此题的花瓶标号是从0开始的。而线段树从1开始
				p = a;//需要找p点之后的花瓶
				int stt = query_fir(1, 1, n);
				if(stt == -1){//一个花瓶都没找到
					printf("Can not put any one.\n");
					continue;
				}
				int tmp = b;
				int ed = query_lst(1, 1, n, tmp);

                printf("%d %d\n", stt-1, ed-1);
                y1 = stt, y2 = ed, p = 1;
                update(1, 1, n);//给stt到ed区间内的花瓶放花
            }
            else if(k == 2){
                if(a > b) swap(a, b);
                a++, b++;
                y1 = a, y2 = b, p = 0;
                int res = query_sum(1, 1, n);
                update(1, 1, n);//把y1和y2区间内的花瓶清空
                printf("%d\n", res);
            }
        }
        printf("\n");
    }
    return 0;
}
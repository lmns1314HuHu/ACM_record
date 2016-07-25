#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 50010
int n, m, x, y;
int a[maxn];

struct node{
    int l, r, _mx, _mxl, _mxr, sum;
    //维护的信息包括：区间内的最大连续和、区间的最大前缀和、区间的最大后缀和、区间的总和；
}tr[maxn*4];

void build(int d, int l, int r){
    tr[d].l = l, tr[d].r = r;
    if(r == l){
        tr[d]._mx = a[l];
        tr[d]._mxl = a[l];
        tr[d]._mxr = a[l];
        tr[d].sum = a[l];
        return;
    }
    int mid=(l+r)>>1, lc=d<<1, rc=d<<1|1;
    build(lc, l, mid);
    build(rc, mid+1, r);
    
    tr[d].sum = tr[lc].sum + tr[rc].sum;
    //父区间的最大连续和是左子最大连续和、右子最大连续和、左子的后缀和+右子前缀和、中的最大值
    tr[d]._mx = max(max(tr[lc]._mx, tr[rc]._mx), tr[lc]._mxr + tr[rc]._mxl);
    //父区间的最大前缀和是左子最大前缀和、左子总和+右子最大前缀和、中的最大值
    tr[d]._mxl = max(tr[lc]._mxl, tr[lc].sum + tr[rc]._mxl);
    //父区间的最大后缀和是右子最大后缀和、右子总和+左子最大后缀和、中的最大值
    tr[d]._mxr = max(tr[rc]._mxr, tr[rc].sum + tr[lc]._mxr);
}

int query(int d, int l, int r, int _kind){//当前节点，目标区间左、右端点，当前取和的类型
    if(_kind == 0){//区间内任意取一段长度，自由的
        if(tr[d].l == l && tr[d].r == r)
            return tr[d]._mx;
        int mid = (tr[d].l+tr[d].r)>>1, lc=d<<1, rc=d<<1|1;
        if(r<=mid){//目标区间在左子
            return query(lc, l, r, 0);
        }
        else if(l > mid){//目标区间在右子
            return query(rc, l, r, 0);
        }
        else{//目标区间在中间
            int res1 = query(lc, l, mid, 0);//左子的自由区间最大连续和
            int res2 = query(rc, mid+1, r, 0);//右子的自由区间的最大连续和
            int res3 = query(lc, l, mid, 1) + query(rc, mid+1, r, 2);//左子的后缀区间最大值+右子的前缀区间的最大值
            return max(max(res1, res2), res3);
        }
    }
    else if(_kind == 1){//区间内只能取后缀和
        if(tr[d].l == l && tr[d].r == r){
            return tr[d]._mxr;
        }
        else{
            int mid1 = (tr[d].l + tr[d].r)>>1, lc=d<<1, rc=d<<1|1;
            if(l <= mid1){//后缀区间左端点在左子上
                return max(tr[rc]._mxr, tr[rc].sum + query(lc, l, mid1, 1));//右子的后缀最大值、左子的后缀最大值+右子的区间总和，中取较大者
            }
            else{//后缀区间整个在右子上
                return query(rc, l, r, 1);
            }
        }
    }
    else if(_kind == 2){//区间内只能取前缀和
        if(tr[d].l == l && tr[d].r == r){
            return tr[d]._mxl;
        }
        else{
            int mid2 = (tr[d].l + tr[d].r)>>1, lc=d<<1, rc=d<<1|1;
            if(r > mid2){
                return max(tr[lc]._mxl, tr[lc].sum + query(rc, mid2+1, r, 2));
            }
            else{
                return query(lc, l, r, 2);
            }
        }
    }
}

int main()
{
    while(~scanf("%d", &n)){
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        build(1, 1, n);
        scanf("%d", &m);
        for (int i = 0; i < m; i++){
            scanf("%d%d", &x, &y);
            printf("%d\n", query(1, x, y, 0));
        }
    }
    return 0;
}

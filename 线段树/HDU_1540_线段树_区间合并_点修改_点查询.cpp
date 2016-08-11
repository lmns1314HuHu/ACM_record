#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;
typedef long long ll;

#define maxn 50010
struct node{
    int l, r;
    int ml, mr, mx;//区间左连续最大长度、区间右连续最大长度、区间中连续最大长度
}tr[maxn*4];

int n, m;
char ch;
int x;

void build(int d, int l, int r){
    tr[d].l = l, tr[d].r = r;
    if(l == r){
        tr[d].mx = tr[d].ml = tr[d].mr = 1;
        return;
    }
    int mid=(l+r)>>1, lc=d<<1, rc=d<<1|1;
    build(lc, l, mid);
    build(rc, mid+1, r);
    tr[d].mx = tr[d].ml = tr[d].mr = tr[lc].mx + tr[rc].mx;
}

void update(int d, int pos, int v){
    if(tr[d].l == tr[d].r && tr[d].l == pos){
        tr[d].mx = tr[d].ml = tr[d].mr = v;
        return;
    }
    int mid = (tr[d].l + tr[d].r) >> 1, lc=d<<1, rc=d<<1|1;
    if(pos <= mid) update(lc, pos, v);
    else update(rc, pos, v);
    
    tr[d].mx = max(max(tr[lc].mx, tr[rc].mx), tr[lc].mr + tr[rc].ml);//区间中的连续最大长度是 左区间内连续最大长度、右区间内连续最大长度、还有中间部分结合起来 中的最大值
    tr[d].ml = tr[lc].ml;//左区间的最连续最大长度是左子的左连续最大长度
    if(tr[lc].ml == tr[lc].r - tr[lc].l + 1)//如果左子的左连续最大长度是整个区间长的话，还要加上右子的左连续最大长度
        tr[d].ml += tr[rc].ml;
    tr[d].mr = tr[rc].mr;
    if(tr[rc].mr == tr[rc].r - tr[rc].l + 1)
        tr[d].mr += tr[lc].mr;
}

int query(int d, int pos){
    if(tr[d].l == tr[d].r || tr[d].mx == 0 || tr[d].mx == tr[d].r - tr[d].l + 1)//如果到子节点 或者 区间最大连续长度是0 或者 区间最大连续长度是整个区间
        return tr[d].mx;
    int mid = (tr[d].l+tr[d].r)>>1, lc=d<<1, rc=d<<1|1;
    if(pos <= mid){
        if(pos >= tr[lc].r - tr[lc].mr + 1){//点在左子的 右连续最大长度内
            int res1 = tr[lc].mr + tr[rc].ml;//点在左子和右子中间那块的最大连续长度
            int res2 = query(lc, pos);//点在左子的最大连续长度
            return max(res1, res2);//取二者最大
        }
        else return query(lc, pos);
    }
    else{
        if(pos <= tr[rc].l + tr[rc].ml - 1){
            int res1 = tr[rc].ml + tr[lc].mr;
            int res2 = query(rc, pos);
            return max(res1, res2);
        }
        else return query(rc, pos);
    }
}

int main()
{
    while(~scanf("%d%d", &n, &m)){
        build(1, 1, n);
        stack<int> stk;
        for (int i = 0; i < m; i++){
            getchar();
            scanf("%c", &ch);
            if(ch == 'D'){
                scanf("%d", &x);
                update(1, x, 0);
                stk.push(x);
            }
            else if(ch == 'R'){
                update(1, stk.top(), 1);
                stk.pop();
            }
            else {
                scanf("%d", &x);
                printf("%d\n", query(1, x));
            }
        }
    }
    return 0;
}

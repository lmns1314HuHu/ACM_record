//本题思路：从数组最后一位开始，将每一个数字加入线段树，更新。以第i位更新后得到的线段树是从第i位到最后一位的不同数字的情况
//用一个map来存储每个数字的下标，在进行更新操作的时候，先查找map中是否有该数字对应的下标，有的话就说明之前出现过这个数字，
//即，上一颗线段树中包含了该数字，那么，我们需要建一个tmp线段树，将上一颗线段树中的该数字除去，然后再根据tmp线段树更新得到以改位置开头到结尾的线段树
//这样，每棵线段树中都能保证不重复不遗漏的统计不同数字的情况。
//为什么要倒着插入呢？方便查询啊！再查寻的时候，只需要找到左端点的线段树，由于这棵线段树维护的是左端点到末尾的不同数字的情况，那么我们只需要
//在这课树上统计qr之前的不同数字的出现的个数就好了！
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;
#define maxn 30010

int n, m;
int val[maxn];

int sum[maxn*100], lc[maxn*100], rc[maxn*100];
int tot, tr[maxn];

void ini(){
    tot = 0;
}

int build(int l, int r){
    int root = tot++;
    sum[root] = 0;
    if(l < r){
        int mid = (l+r)>>1;
        lc[root] = build(l, mid);
        rc[root] = build(mid+1, r);
    }
    return root;
}

int update(int Lroot, int l, int r, int pos, int val){
    int newroot = tot++, mid = (l+r)>>1;
    sum[newroot] = sum[Lroot] + val;
    if(l < r){
        if(pos <= mid){
            lc[newroot] = update(lc[Lroot], l, mid, pos, val);
            rc[newroot] = rc[Lroot];
        }
        else{
            lc[newroot] = lc[Lroot];
            rc[newroot] = update(rc[Lroot], mid+1, r, pos, val);
        }
    }
    return newroot;
}

int query(int Lroot, int qr, int l, int r){//查询l，r区间内的不同的数的个数时，查询以l开头的序列的线段树，查找其中小于r范围内的不同数的个数。
    int mid = (l+r)>>1, ans = 0;
    if(r <= qr) return sum[Lroot];
    ans += query(lc[Lroot], qr, l, mid);
    if(qr > mid) ans += query(rc[Lroot], qr, mid+1, r);
    return ans;
}

int main()
{
    while(~scanf("%d", &n)){
        for (int i = 1; i <= n; i++)
            scanf("%d", &val[i]);
        ini();
        tr[n+1] = build(1, n);
        map<int, int> ms;//用map记住上一个出现该数字的idx
        for (int i = n; i >= 1; i--){
            if(ms.find(val[i]) == ms.end()){//如果没出现过，那么直接更新
                tr[i] = update(tr[i+1], 1, n, i, 1);
            }
            else{//如果出现过该数字，先要把上一颗线段树中对应的出现过该数的位置变成-1，这样得到的tmp树，是不包含该数字的。然后在根据tmp树，更新树
                int tmp = update(tr[i+1], 1, n, ms[val[i]], -1);
                tr[i] = update(tmp, 1, n, i, 1);
            }
            ms[val[i]] = i;//并更新该数字此次出现的位置，为下次可能出现相同数字的情况做好准备
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++){
            int ql, qr;
            scanf("%d%d", &ql, &qr);
            if(ql > qr) swap(ql, qr);
            printf("%d\n", query(tr[ql], qr, 1, n));
        }
    }
    return 0;
}

/**************************************************************
    Problem: 2038
    User: lmns
    Language: C++
    Result: Accept
****************************************************************/
 
/**==================================
 | Author: YunHao
 | OJ: 
 | Kind: 
 | Date: 
 | Describe:
 |          
 |          
 =================================**/
 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
 
using namespace std;
typedef long long ll;
#define maxn 50010
#define maxm 50010
 
int n, m, unit;//unit存分块的信息
int a[maxn];
int num[maxn];//num[i] = j表示i这个数字出现了j次
 
struct Query{//存储所有询问
    int L, R, id;
}node[maxm];
 
struct Ans{//存储所有询问的结果
    ll a,b;
    void reduce(){
        ll d = __gcd(a, b);
        a /= d, b /= d;
    }
}ans[maxm];
 
bool cmp(Query q1, Query q2){//分块排序
    if(q1.L/unit == q2.L/unit) return q1.R < q2.R;
    return q1.L/unit < q2.L/unit;
}
 
void work(){//莫队算法，由L，R区间可以推出L，R-1区间、L，R+1区间、L-1，R区间，L+1，R区间的时候可以使用莫队算法
    memset(num, 0, sizeof num);
    ll temp = 0;
    int L = 1, R = 0;
    for(int i = 0; i < m; i++){
        while(R < node[i].R){
            R++;
            temp -= (ll)(num[a[R]]*num[a[R]]);
            num[a[R]]++;
            temp += (ll)(num[a[R]]*num[a[R]]);
        }
        while(R > node[i].R){
            temp -= (ll)(num[a[R]]*num[a[R]]);
            num[a[R]]--;
            temp += (ll)(num[a[R]]*num[a[R]]);
            R--;
        }
        while(L < node[i].L){
            temp -= (ll)(num[a[L]]*num[a[L]]);
            num[a[L]]--;
            temp += (ll)(num[a[L]]*num[a[L]]);
            L++;
        }
        while(L > node[i].L){
            L--;
            temp -= (ll)(num[a[L]]*num[a[L]]);
            num[a[L]]++;
            temp += (ll)(num[a[L]]*num[a[L]]);
        }
        ans[node[i].id].a = temp - (R-L+1);
        ans[node[i].id].b = (ll)(R-L)*(R-L+1);//一定要先把R-L转化成ll再做乘法，否则((ll)(R-L)*(R-L+1))中间结果会爆int，会wa
        ans[node[i].id].reduce();
    }
}
 
int main()
{
    while(~scanf("%d%d", &n, &m)){
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < m; i++){
            node[i].id = i;
            scanf("%d%d", &node[i].L, &node[i].R);
        }

        unit = (int)sqrt(n);//对询问进行分块排序
        sort(node, node+m, cmp);//将查询区间分成sqrt(n)个sqrt(n)大小的块，按照这么分的话，能保证所有的 相邻两个询问的转移代价 之和最小。

        work();

        for (int i = 0; i < m; i++){
            printf("%lld/%lld\n", ans[i].a, ans[i].b);
        }
    }
    return 0;
}

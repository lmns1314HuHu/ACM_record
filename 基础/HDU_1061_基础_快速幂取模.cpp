/**==================================
 | Author: YunHao
 | OJ: HDU
 | Kind: 快速幂取模
 | Date: 2016/8/1
 | Describe:
 |          
 |          
 =================================**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

#define mod 10
ll fpow(ll num, ll n){
    ll ret = 1;
    while(n){
        if(n&1)
            ret = (ret * num) % mod;
        num = (num * num) % mod;
        n >>= 1;
    }
    return ret;
}

int t;
ll n;

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        ll res = fpow(n, n);
        printf("%lld\n", res);
    }
    return 0;
}

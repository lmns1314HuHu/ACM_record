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

ll dp[30];

ll C(ll a, ll b){
    if(b > a-b) b = a-b;
    ll res = 1;
    for (int i = 0; i < b; i++){
        res = res * (a-i)/(i+1);
    }
    return res;
}

int main()
{
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= 25; i++)
        dp[i] = (i-1)*(dp[i-1] + dp[i-2]);
    int t, n;
    while(~scanf("%d", &n) && n){
        int mid = floor(n / 2.0);
        ll res = 0;
        for (int i = mid; i >= 0; i--){
            res += (C(n, i) * dp[i]);
        }
        printf("%lld\n", res + 1);
    }
    return 0;
}

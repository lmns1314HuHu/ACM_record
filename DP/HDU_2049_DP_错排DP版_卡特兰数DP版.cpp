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

using namespace std;
typedef long long ll;

ll dp[25];

ll C(int a, int b){
    if(b > a-b) b = a-b;
    ll res = 1;
    for (int i = 0; i < b; i++){
        res = res * (a-i) / (i+1);
    }
    return res;
}

int main()
{
    dp[0] = dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= 20; i++){
        dp[i] = (i-1)*(dp[i-1] + dp[i-2]);
    }
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        ll res = C(a, b) * dp[b];
        printf("%lld\n", res);
    }
    return 0;
}

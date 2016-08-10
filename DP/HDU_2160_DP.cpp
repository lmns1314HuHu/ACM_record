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

ll dp[25];//第i天出生的猪的数量
ll num[25];//第i天养猪场的猪总数

int main()
{
    dp[1] = 1; num[1] = 1;
    dp[2] = 1; num[2] = 2;
    for (int i = 3; i <= 20; i++){//相当于num[i]=num[i-1]*2-num[i-3];
        num[i] = num[i-1] * 2;
        dp[i] = num[i-1];
        num[i] -= dp[i-2];
    }
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%lld\n", num[n]);
    }
    return 0;
}

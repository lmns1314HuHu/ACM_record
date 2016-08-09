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

ll dp[50][3];

int main()
{
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= 40; i++){
        dp[i][0] = dp[i-1][1] + dp[i-1][2];
        dp[i][1] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
        dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
    }
    int n;
    while(~scanf("%d", &n))
        printf("%lld\n", dp[n][0] + dp[n][1] + dp[n][2]);
    return 0;
}

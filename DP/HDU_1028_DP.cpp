/**==================================
 | Author: YunHao
 | OJ: POJ 1125
 | Kind: DP
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

int dp[125][125];

int main()
{
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= 120; i++){
        for (int j = 1; j <= i; j++){
            if(i-j > j)
                dp[i][j] = dp[i][j-1] + dp[i-j][j];
            else
                dp[i][j] = dp[i][j-1] + dp[i-j][i-j];
        }
    }
    int n;
    while(~scanf("%d", &n)){
        printf("%d\n", dp[n][n]);
    }
    return 0;
}

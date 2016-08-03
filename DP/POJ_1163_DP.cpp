/**==================================
 | Author: YunHao
 | OJ: POJ 1163
 | Kind: DP
 | Date: 2016/8/2
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

int n;
int dp[110][110];

int main()
{
    while(~scanf("%d", &n)){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= i; j++){
                scanf("%d", &dp[i][j]);
            }
        }
        for (int i = n-1; i >= 1; i--){
            for (int j = 1; j <= i; j++){
                dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + dp[i][j];
            }
        }
        printf("%d\n", dp[1][1]);
    }
    return 0;
}

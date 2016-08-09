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

int n;
ll dp[40][2];

int main()
{
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i <= 33; i++){
        dp[i][0] = dp[i-1][0]*3 + dp[i-1][1]*2;
        dp[i][1] = dp[i-1][0] + dp[i-1][1];
    }
    while(~scanf("%d", &n)){
        if(n == -1) break;
        printf("%lld, %lld\n", dp[n][0], dp[n][1]);
    }
    return 0;
}

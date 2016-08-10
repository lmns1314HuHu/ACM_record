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

ll dp[2010][2010];

int main()
{
    dp[1][1] = 1;
    for (int i = 2; i <= 2000; i++){
        for (int j = 1; j <= i; j++){
            dp[i][j] = (dp[i-1][j-1] + (dp[i-1][j] * (j%1000)) % 1000) % 1000;
        }
    }
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int res = 0;
        for (int i = 1; i <= n; i++){
            res = (res + dp[n][i]) % 1000;
        }
        printf("%d\n", res);
    }
    return 0;
}

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

ll dp[40][40];

int main()
{
    dp[0][0] = 1;
    for (int i = 0; i < 40; i++){
        for (int j = i; j < 40; j++){
            if(i == j) dp[i][j+1] += dp[i][j];
            else{
                dp[i][j+1] += dp[i][j];
                dp[i+1][j] += dp[i][j];
            }
        }
    }
    int n, w = 1;
    while(~scanf("%d", &n)){
        if(n==-1) break;
        printf("%d %d %lld\n", w++, n, 2*dp[n][n]);
    }
    return 0;
}

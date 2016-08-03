/**==================================
 | Author: YunHao
 | OJ: POJ
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

int f, v;
int a[110][110];
int dp[110][110];

int main()
{
    while(~scanf("%d%d", &f, &v)){
        for (int i = 1; i <= f; i++){
            for (int j = 1; j <= v; j++){
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 1; i <= v; i++)
            dp[1][i] = a[1][i];
        for (int i = 2; i <= f; i++){
            int maxv = -10000000;
            for (int j = i; j <= v-(f-i); j++){
                maxv = max(maxv, dp[i-1][j-1]);
                dp[i][j] = maxv + a[i][j];
            }
        }
        int mx = -1000000;
        for (int i = f; i <= v; i++){
            if(dp[f][i] > mx)
                mx = dp[f][i];
        }
        printf("%d\n", mx);
    }
    return 0;
}

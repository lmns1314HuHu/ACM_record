#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define mod 1000000007
int t;
int dp[2010][2010];
int dp2[2010][2010];
int a, b;

int main()
{
    int ca = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d-%d", &a, &b);

        memset(dp, 0, sizeof(dp));
        memset(dp2, 0, sizeof(dp2));

        for (int i = 0; i <= a; i++){
            if(i != 0){
                dp[i][0] = 1;
                dp2[i][0] = 1;
            }
            for (int j = 1; j <= b; j++){

                if(i-1 > j){
                    dp[i][j] = (dp[i][j] % mod +  dp[i-1][j] % mod) % mod;
                }
                if(i > j-1){
                    dp[i][j] = (dp[i][j] % mod + dp[i][j-1] % mod) % mod;
                }
                if(i-1 >= j){
                    dp2[i][j] = (dp2[i][j] % mod +  dp2[i-1][j] % mod) % mod;
                }
                if(i >= j-1){
                    dp2[i][j] = (dp2[i][j] % mod + dp2[i][j-1] % mod) % mod;
                }
            }
        }

        printf("Case #%d: %d %d\n", ca++, dp[a][b], max(1,dp2[b][b]));
    }
    return 0;
}

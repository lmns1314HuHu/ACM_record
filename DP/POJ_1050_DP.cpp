#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
#define maxn 110

int n;
int a;
int num[maxn][maxn];
int dp[maxn][maxn];

int main()
{
    while(~scanf("%d", &n)){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                scanf("%d", &a);
                num[i][j] = num[i][j-1] + a;
            }
        }
        int ans = -1300000;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n - i + 1; j++){
                dp[i][j] = num[1][i+j-1] - num[1][i-1];
            }
        }
        for (int i = 2; i <= n; i++){
            for (int j = 1; j <= n; j++){
                for (int k = 1; k <= n - j + 1; k++){
                    int s = num[i][k+j-1] - num[i][j-1];
                    dp[j][k] = max(dp[j][k] + s, s);
                    if(dp[j][k] > ans){
                        ans = dp[j][k];
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

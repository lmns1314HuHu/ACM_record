#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define inf 0x3f3f3f3f
int n;
int dp[100010][3];
int a[100010];

int main()
{
    while(~scanf("%d", &n)){
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        memset(dp, inf, sizeof dp);
        dp[0][0] = inf;
        if(a[1] == a[0]) dp[0][1] == 0;
        dp[0][2]=a[1]-a[0];
        for (int i = 1; i < n; i++){
            dp[i][0] = dp[i-1][1] + a[i]-a[i-1];
            dp[i][1] = dp[i-1][2];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + a[i+1]-a[i];
        }
        printf("%d\n", min(dp[n-1][0], dp[n-1][1]));
    }
    return 0;
}

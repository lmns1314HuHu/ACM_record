#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m;
int w[4000];
int d[4000];
int dp[20000];

int main()
{
    while(~scanf("%d%d", &n, &m)){
        for (int i = 0; i < n; i++){
            scanf("%d%d", &w[i], &d[i]);
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++){
            for (int j = m; j >= 1; j--){
                if(j >= w[i]){
                    dp[j] = max(dp[j], dp[j-w[i]]+d[i]);
                }
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}

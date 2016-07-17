#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int v[55];
int m[55];

int w[5010];
//int c[5010];
int dp[125010];
int total;

//multiple bag -> 01 bag
int main()
{
    while(~scanf("%d", &n)){
        if(n < 0) break;
        total = 0;
        int k = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++){
            scanf("%d%d", &v[i], &m[i]);
            total += (v[i] * m[i]);
            for (int j = 1; j <= m[i]; j++){
                w[k++] = v[i] * j;
            }
        }
        int c = total / 2;
        for (int i = 0; i < k; i++){
            for (int j = c; j >= w[i]; j--){
                dp[j] = max(dp[j], dp[j-w[i]] + w[i]);
            }
        }
        printf("%d %d\n", total-dp[c], dp[c]);
    }
    return 0;
}

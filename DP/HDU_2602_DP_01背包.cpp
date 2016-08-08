#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, v, t;
#define maxn 1010
#define maxv 1010
int w[maxn];
int p[maxn];
int dp[maxv];

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &v);
        for (int i = 0; i < n; i++){
            scanf("%d", p+i);
        }
        for (int i = 0; i < n; i++){
            scanf("%d", w+i);
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++){
            for (int j = v; j >= w[i]; j--){
                dp[j] = max(dp[j], dp[j-w[i]] + p[i]);
            }
        }
        printf("%d\n", dp[v]);
    }
    return 0;
}

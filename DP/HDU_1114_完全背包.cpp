#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int t, e, f;
int n;
int w[510];
int p[510];
int dp[10010];

//total bag
int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &e, &f);
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%d%d", &p[i], &w[i]);
        }
        for (int i = 0; i <= f-e; i++){
            dp[i] = 999999999;
        }
        dp[0] = 0;
        for (int i = 0; i < n; i++){
            for (int j = w[i]; j <= f-e; j++){
                dp[j] = min(dp[j], dp[j-w[i]] + p[i]);
            }
        }
        if(dp[f-e] == 999999999){
            printf("This is impossible.\n");
        }
        else{
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[f-e]);
        }
    }
    return 0;
}

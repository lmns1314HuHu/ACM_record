#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
#define maxn 1005
long long num[maxn];
long long dp[maxn];

//longest increasing sequence
//n2
int main()
{
    while(~scanf("%d", &n)){
        if(n == 0) break;
        for (int i = 0; i < n; i++){
            scanf("%lld", num + i);
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = num[0];
        long long ans = 0;

        for (int i = 0; i < n; i++){

            dp[i] = num[i];

            for (int j = 0; j < i; j++){
                if(num[j] < num[i]){
                    dp[i] = max(dp[i], dp[j] + num[i]);
                }
            }
            ans = max(ans, dp[i]);

//            cout << i << ": ";
//            for (int k = 0; k < n; k++){
//                cout << dp[k] << " ";
//            }
//            cout << endl;

        }
        printf("%lld\n", ans);
    }
    return 0;
}

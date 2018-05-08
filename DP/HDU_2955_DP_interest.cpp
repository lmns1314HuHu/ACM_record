#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

int t, n, m[110];
double totp, p[110];
double dp[10010];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lf %d", &totp, &n);
        totp = 1 - totp;
        int sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d %lf", &m[i], &p[i]);
            sum += m[i];
            p[i] = 1 - p[i];
        }

        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int i = 0; i < n; i++){
            for (int j = sum; j >= m[i]; j--){
                dp[j] = max(dp[j], dp[j-m[i]] * p[i]);
            }
        }

        for (int i = sum; i >= 0; i--){
            if(dp[i] >= totp){
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}

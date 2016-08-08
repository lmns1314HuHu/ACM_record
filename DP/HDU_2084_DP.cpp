#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[105][105];
int t, n;
int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= i; j++){
                scanf("%d", &dp[i][j]);
            }
        }
        for (int i = n - 2; i >= 0; i--){
            for (int j = 0; j <= i; j++){
                dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + dp[i][j];
            }
        }
        printf("%d\n", dp[0][0]);

//        for (int i = 0; i < n; i++){
//            for (int j = 0; j <= i; j++){
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
    }
    return 0;
}

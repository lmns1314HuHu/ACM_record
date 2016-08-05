/**==================================
 | Author: YunHao
 | OJ: POJ
 | Kind: DP
 | Date: 2016/8/3
 | Describe:
 |          
 |          
 =================================**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int c, n, m;
double dp[2][105];

int main()
{
    while(~scanf("%d", &c) && c){
        scanf("%d%d", &n, &m);
        for (int i = 0; i < 2; i++){
            for (int j = 0; j <= 104; j++){
                dp[i][j] = 0;
            }
        }
        if(m > c || m > n){
            printf("0.000\n");
            continue;
        }
        if(m % 2 != n % 2){//当n和m不同时为奇数或者是偶数的时候
            printf("0.000\n");
            continue;
        }
        if(n > 1000){//当n的值大于1000，概率趋近于一个定值，这样会防止TLE
            n=1000+n%2;
        }
        dp[0][0] = 1.0;//特判，注意
        dp[1][1] = 1.0;
		
        for (int i = 2; i <= n; i++){
            int mx = min(i, c);
            for(int j = 0; j <= mx; j++){
                dp[i%2][j] = 0;
                if((i + j) % 2 == 1) continue;
                if(j-1 >= 0)
                    dp[i%2][j] = dp[i%2][j] + dp[(i-1)%2][j-1] * (double)(c-j+1) / (double)c;
                if(j+1 <= mx)
                    dp[i%2][j] = dp[i%2][j] + dp[(i-1)%2][j+1] * (double)(j+1) / (double)c;
            }
        }
        printf("%.3lf\n", dp[n%2][m]);
    }
    return 0;
}

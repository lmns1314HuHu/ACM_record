/**==================================
 | Author: YunHao
 | OJ: 
 | Kind: 
 | Date: 
 | Describe:
 |          
 |          
 =================================**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

ll dp[22];

int main()
{
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= 20; i++){
        dp[i] = (i-1)*(dp[i-1] + dp[i-2]);
    }
    int n, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        double res = dp[n];
        for (int i = 1; i <= n; i++){
            res /= i;
        }
        res *= 100;
        printf("%.2lf%%\n", res);
    }
    return 0;
}

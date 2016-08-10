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

ll dp[50];

int main()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    for (int i = 5; i <= 55; i++){
        dp[i] = dp[i-1] + dp[i-3];
    }
    int n;
    while(~scanf("%d", &n) && n){
        printf("%lld\n", dp[n]);
    }
    return 0;
}

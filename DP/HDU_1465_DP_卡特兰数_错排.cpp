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

ll dp[30];

int main()
{
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= 20; i++)
        dp[i] = (i-1)*(dp[i-1] + dp[i-2]);
    int n;
    while(~scanf("%d", &n))
        printf("%lld\n", dp[n]);
    return 0;
}

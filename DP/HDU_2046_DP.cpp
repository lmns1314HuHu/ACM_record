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

ll dp[55];

int main()
{
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 50; i++)
        dp[i] = dp[i-1]+dp[i-2];
    int n;
    while(~scanf("%d", &n))
        printf("%lld\n", dp[n]);
    return 0;
}

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

ll dp[40];

int main()
{
    dp[1] = 1;
    for (int i = 2; i <= 30; i++){
        dp[i] = (dp[i-1]+1)*2;
    }
    int n;
    while(~scanf("%d", &n))
        printf("%lld\n", dp[n]);
    return 0;
}

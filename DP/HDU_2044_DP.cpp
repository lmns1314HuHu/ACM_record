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
int t, a, b;

int main()
{
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= 50; i++)
        dp[i] = dp[i-1] + dp[i-2];
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        printf("%lld\n", dp[b-a+1]);
    }
    return 0;
}

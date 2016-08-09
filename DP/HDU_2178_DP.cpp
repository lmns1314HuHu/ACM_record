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
    dp[1] = 1;
    for (int i = 2; i <= 30; i++)
        dp[i] = 2*dp[i-1] + 1;
    int n, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }
    return 0;
}

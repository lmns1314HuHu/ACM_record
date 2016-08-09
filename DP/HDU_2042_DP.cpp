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

ll dp[35];

int main()
{
    dp[0] = 3;
    for (int i = 1; i <= 30; i++)
        dp[i] = (dp[i-1]-1)*2;
    int n, a;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &a);
        printf("%lld\n", dp[a]);
    }
    return 0;
}

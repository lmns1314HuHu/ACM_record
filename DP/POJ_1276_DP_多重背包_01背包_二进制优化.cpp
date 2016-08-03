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

int cash, n;
int money, mount;
int dp[100005];
int val[10010];

int main()
{
    while(~scanf("%d", &cash)){
        scanf("%d", &n);
        int cnt = 0;
        for (int i = 0; i < n; i++){
            scanf("%d%d", &mount, &money);
            int k = 1;
            while(mount > 0){
                k = min(mount, k);
                val[cnt++] = k * money;
                mount -= k;
                k *= 2;
            }
        }
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < cnt; i++){
            for (int j = cash; j >= val[i]; j--){
                dp[j] = max(dp[j], dp[j-val[i]] + val[i]);
            }
        }
        printf("%d\n", dp[cash]);
    }
    return 0;
}

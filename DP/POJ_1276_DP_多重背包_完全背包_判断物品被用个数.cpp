/**==================================
 | Author: YunHao
 | OJ: POJ
 | Kind: 多重背包
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
int mount[13], money[13];
int dp[100010];
int num[100010];

int main()
{
    while(~scanf("%d", &cash)){
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d %d", &mount[i], &money[i]);
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; i++){
            memset(num, 0, sizeof num);//记录每种硬币所用的个数
            for (int j = money[i]; j <= cash; j++){
                if(dp[j] < dp[j-money[i]] + money[i] && num[j-money[i]] < mount[i]){//加个判断，判断是否用多了
                    dp[j] = dp[j-money[i]] + money[i];
                    num[j] = num[j-money[i]]+1;
                }
            }
        }
        printf("%d\n", dp[cash]);
    }
    return 0;
}

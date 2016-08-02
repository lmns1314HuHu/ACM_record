/**==================================
 | Author: YunHao
 | OJ: HDU
 | Kind: 打表+DP
 | Date: 2016/8/1
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

int n;
int dp[6000];

int main()
{
    int k = 0;
    dp[0] = 1;
    int p2 = 0, p3 = 0, p5 = 0, p7 = 0;
    for (int i = 1; i <= 5842 ;i++){
        while(dp[p2]*2 <= dp[i-1]) p2++;//找到刚好比上一个丑数大的丑数
        while(dp[p3]*3 <= dp[i-1]) p3++;
        while(dp[p5]*5 <= dp[i-1]) p5++;
        while(dp[p7]*7 <= dp[i-1]) p7++;
        int tmp = dp[p2]*2;//比较出这四个数的顺序
        if(dp[p3]*3 < tmp) tmp = dp[p3]*3;
        if(dp[p5]*5 < tmp) tmp = dp[p5]*5;
        if(dp[p7]*7 < tmp) tmp = dp[p7]*7;
        dp[i] = tmp;//把最小的丑数赋值
    }
    while(~scanf("%d", &n) && n){
        if(n % 10 == 1 && n % 100 != 11)//11的序数词是eleventh
            printf("The %dst humble number is %d.\n", n, dp[n-1]);
        else if(n % 10 == 2 && n % 100 != 12)//12的序数词是twelfth
            printf("The %dnd humble number is %d.\n", n, dp[n-1]);
        else if(n % 10 == 3 && n % 100 != 13)//
            printf("The %drd humble number is %d.\n", n, dp[n-1]);
        else
            printf("The %dth humble number is %d.\n", n, dp[n-1]);
    }
    return 0;
}

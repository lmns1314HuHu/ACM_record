/**==================================
 | Author: YunHao
 | OJ: HDU
 | Kind: 暴力
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

double num;

int main()
{
    while(~scanf("%lf", &num) && num){
        double ans = 0;
        int cnt = 0;
        for (int i = 2; ans < num; i++){
            ans += (double)(1.0 / (double)i);
            cnt++;
        }
        printf("%d card(s)\n", cnt);
    }
    return 0;
}

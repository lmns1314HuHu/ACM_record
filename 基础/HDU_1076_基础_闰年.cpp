/**==================================
 | Author: YunHao
 | OJ: HDU 1076
 | Kind: leap year
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

bool isLeap(int year){
    if((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}

int main()
{
    int a, b, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        int cnt = 0, i = a;
        for ( ; cnt < b; i++){
            if(isLeap(i))
                cnt++;
        }
        printf("%d\n", i-1);
    }
    return 0;
}

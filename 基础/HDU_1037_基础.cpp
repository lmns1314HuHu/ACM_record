/**==================================
 | Author: YunHao
 | OJ: HDU
 | Kind: 大水题
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

int a, b, c;

int main()
{
    while(~scanf("%d%d%d", &a, &b, &c)){
        int cnt = 0;
        if(a <= 168) cnt++;
        if(b <= 168) cnt++;
        if(c <= 168) cnt++;
        if(cnt == 0)
            printf("NO CRASH\n");
        else{
            printf("CRASH");
            if(a <= 168) printf(" %d", a);
            if(b <= 168) printf(" %d", b);
            if(c <= 168) printf(" %d", c);
            printf("\n");
        }
    }
    return 0;
}

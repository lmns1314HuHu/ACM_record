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
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
    int a, b;
    while(~scanf("%d%d", &a, &b)){
        if (a > b) swap(a, b);
        int k = b-a;
        int tmpa = (int)((1 + sqrt(5.0)) / 2 * k);
        int tmpb = tmpa + k;
        if(tmpa == a && tmpb == b){
            printf("0\n");
        }
        else printf("1\n");
    }
    return 0;
}

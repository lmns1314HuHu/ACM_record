/**==================================
 | Author: YunHao
 | OJ: HDU
 | Kind: 水题
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
int t, n;
int num[1010];
int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        sort(num, num + n);
        for (int i = 0; i < n-1; i++)
            printf("%d ", num[i]);
        printf("%d\n", num[n-1]);
    }
    return 0;
}

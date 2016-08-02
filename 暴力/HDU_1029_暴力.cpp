/**==================================
 | Author: YunHao
 | OJ: HDU
 | Kind: baoli
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
#include <map>

using namespace std;
typedef long long ll;

int n, num;
map<int, int> ms;

int main()
{
    while(~scanf("%d", &n)){
        ms.clear();
        int flag = (n+1)/2;
        int res = -1;
        for (int i = 0; i < n; i++){
            scanf("%d", &num);
            ms[num]++;
            if(ms[num] >= flag){
                res = num;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

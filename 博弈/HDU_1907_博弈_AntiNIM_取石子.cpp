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

int t, n;
int num;

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        bool flag = false;
        int res = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &num);
            if(num > 1) flag = true;
            res ^= num;
        }
        if(res == 0 && !flag)
            printf("John\n");
        else if(res != 0 && flag)
            printf("John\n");
        else printf("Brother\n");
    }
    return 0;
}

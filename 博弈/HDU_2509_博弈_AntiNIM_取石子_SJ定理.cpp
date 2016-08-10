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

int main()
{
    int n;
    int num;
    while(~scanf("%d", &n)){
        int res = 0;
        bool flag = false;
        for (int i = 0; i < n; i++){
            scanf("%d", &num);
            if(num > 1) flag = true;
            res ^= num;
        }
        if(res == 0 && !flag){
            printf("Yes\n");
        }
        else if(res != 0 && flag){
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}

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

int n;
int num[200010];

int main()
{
    while(~scanf("%d", &n) && n){
        int res = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &num[i]);
            res ^= num[i];
        }
        sort(num, num + n);
        if(res != 0){
            printf("Yes\n");
            for (int i = 0; i < n; i++){
                if((res ^ num[i]) <= num[i]){
                    printf("%d %d\n", num[i], res^num[i]);
                }
            }
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}

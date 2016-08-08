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
int num[1010];

int main()
{
    while(scanf("%d", &n)&&n){
        int res = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &num[i]);
            res ^= num[i];
        }
        int cnt = 0;
        if(res == 0){
            printf("0\n");
            continue;
        }
        for (int i = 0; i < n; i++){
            if((res^num[i]) <= num[i])
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}

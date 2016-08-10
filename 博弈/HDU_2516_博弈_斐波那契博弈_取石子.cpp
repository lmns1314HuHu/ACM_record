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

ll f[55];

int main()
{
    f[0] = 2;
    f[1] = 3;
    for(int i = 2; i <= 50; i++){
        f[i] = f[i-1] + f[i-2];
    }
    ll n;
    while(~scanf("%lld", &n) && n){
        bool flag = false;
        for (int i = 0; i <= 50; i++){
            if(f[i] > n) break;
            if(f[i] == n){
                flag = true;
                break;
            }
        }
        if(!flag) printf("First win\n");
        else printf("Second win\n");
    }
    return 0;
}

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

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int res = 1;
        for (int i = 2; i*i <= n; i++){
            if(n % i == 0){
                int nage = n / i;
                res += i;
                if(nage != i) res += nage;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

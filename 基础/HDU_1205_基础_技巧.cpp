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
    int t, n;
    ll a;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ll sum = 0;
        ll mx = 0;
        for (int i = 0; i < n; i++){
            scanf("%lld", &a);
            sum += a;
            if(a > mx)mx = a;
        }
        if(sum-mx+1 >= mx)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

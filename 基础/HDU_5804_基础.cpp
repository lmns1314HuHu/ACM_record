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

int t, n, m;
int num;
ll q[100010];

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        ll sum = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &num);
            sum += num;
        }
        for (int i = 0; i < m; i++){
            scanf("%lld", &q[i]);
        }
        for (int i = 0; i < m; i++){
            if(q[i] > sum)
                printf("1");
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}

/**==================================
 | Author: YunHao
 | OJ: POJ
 | Kind: DP
 | Date: 2016/8/3
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
#define inf 100000000

int n, num, a, b;
int peo[110][110];

int main()
{
    while(~scanf("%d", &n) && n){
        for (int i = 0; i < 110; i++){
            for (int j = 0; j < 110; j++){
                if(i == j) peo[i][j] = 0;
                else peo[i][j] = inf;
            }
        }
        for (int i = 1; i <= n; i++){
            scanf("%d", &num);
            for (int j = 0; j < num; j++){
                scanf("%d%d", &a, &b);
                peo[i][a] = b;
            }
        }
        for (int k = 1; k<= n; k++){
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    if(peo[i][k] + peo[k][j] < peo[i][j])
                        peo[i][j] = peo[i][k] + peo[k][j];
                }
            }
        }
        int peoid = 0, restime = 100000000;
        for (int i = 1; i <= n; i++){
            int total_time = 0;
            for (int j = 1; j <= n; j++){
                if(peo[i][j] > total_time)
                    total_time = peo[i][j];
            }
            if(total_time < restime){
                peoid = i;
                restime = total_time;
            }
        }
        printf("%d %d\n", peoid, restime);
    }
    return 0;
}

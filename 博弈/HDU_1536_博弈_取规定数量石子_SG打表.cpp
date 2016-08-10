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

int k, m, n;
int num[110];
int sg[10010];
bool visit[10010];

void getsg(){
    sort(num, num + k);
    int i;
    for (i = 0; i < num[0]; i++)
        sg[i] = 0;
    for ( ; i <= 10000; i++){
        memset(visit, 0, sizeof visit);
        for (int j = 0; num[j] <= i && j < k; j++){
            visit[sg[i-num[j]]] = true;
        }
        for (int j = 0; ; j++){
            if(!visit[j]){
                sg[i] = j;
                break;
            }
        }
    }
    //for (int ii = 0; ii < 100; ii++){
        //cout << sg[ii] << endl;
    //}
}

int main()
{
    while(~scanf("%d", &k) && k){
        for (int i = 0; i < k; i++){
            scanf("%d", &num[i]);
        }
        getsg();

        scanf("%d", &n);
        while(n--){
            int l, shizi, res = 0;
            scanf("%d", &l);
            for (int i = 0; i < l; i++){
                scanf("%d", &shizi);
                res ^= sg[shizi];
            }
            if(res != 0) printf("W");
            else printf("L");
        }
        printf("\n");
    }
    return 0;
}

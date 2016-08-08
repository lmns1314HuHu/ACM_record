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

int k;
int num[105];
int m, l, shizi;
int sg[10010];

bool visit[10010];
void getsg(){
    sort(num, num + k);
    sg[0] = 0;
    int i;
    for (i = 1; i < num[0]; i++){
        sg[i] = 0;
    }
    for ( ; i < 10010; i++){
        memset(visit, 0, sizeof visit);
        int j = 0;
        for (; num[j] <= i && j < k; j++){
            visit[sg[i - num[j]]] = true;
        }
        for (int j = 0; ; j++){
            if(!visit[j]){
                sg[i] = j;
                break;
            }
        }
    }
    //for (int i = 0; i < 100; i++){
        //cout << "sg[" << i << "] = " << sg[i] << endl;
    //}
    //cout << endl;
}

int main()
{
    while(~scanf("%d", &k)&&k){
        for (int i = 0; i < k; i++){
            scanf("%d", &num[i]);
        }
        getsg();
        scanf("%d", &m);
        for (int i = 0; i < m; i++){
            scanf("%d", &l);
            int res = 0;
            for (int j = 0; j < l; j++){
                scanf("%d", &shizi);
                res ^= sg[shizi];
            }
            if(res == 0)printf("L");
            else printf("W");
        }
        printf("\n");
    }
    return 0;
}

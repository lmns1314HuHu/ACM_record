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
#include <cmath>
using namespace std;
typedef long long ll;

int sg[1010][1010];
bool visit[1010000];
void getsg(){
    for (int i = 0; i <= 100; i++){
        sg[0][i] = 1;
        sg[i][0] = 1;
    }
    sg[0][0] = 0;
    for (int i = 1; i < 100; i++){
        for (int j = 1; j < 100; j++){
            memset(visit, 0, sizeof visit);

            for (int m = 1; m <= i; m++){
                visit[sg[i-m][j]] = true;
            }
            for (int m = 1; m <= j; m++){
                visit[sg[i][j-m]] = true;
            }
            for (int m = 1; m <= i && m <= j; m++){
                visit[sg[i-m][j-m]] = true;
            }
            for (int m = 0; ; m++){
                if(!visit[m]){
                    sg[i][j] = m;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            cout << sg[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int a, b;
    while(~scanf("%d%d", &a, &b)){
        if(a==0 && b==0) break;
        int k = b - a;
        int tmpa = (int)((1+sqrt(5.0)) / 2.0 * k);
        int tmpb = tmpa + k;
        if (tmpa == a && tmpb == b){
            printf("0\n");
        }
        else{
            printf("1\n");
            if(tmpa < a && tmpb < b){
                printf("%d %d\n", tmpa, tmpb);
            }
            for (int i = 0; i < b; i++){
                int tmpk = abs(a-i);
                int tm1 = (int)((1 + sqrt(5.0)) / 2.0 * tmpk);
                int tm2 = tm1 + tmpk;
                if(tm1 == min(a, i) && tm2 == max(a, i)){
                    printf("%d %d\n", tm1, tm2);
                }
            }
        }
    }
    return 0;
}

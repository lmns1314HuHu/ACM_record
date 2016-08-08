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
int sg[2010];//表示长度为i的棋盘对应的sg值

bool visit[2010];
void getsg(){
    sg[0] = 0;
    sg[1] = sg[2] = 1;
    sg[3] = 1;
    for (int i = 4; i < 2005; i++){
        memset(visit, 0, sizeof visit);
        visit[sg[i-3]] = true;
        visit[sg[i-4]] = true;
        visit[sg[i-5]] = true;
        int tmp = 0;
        for (int j = 1; j < i; j++){
            int k = i-5-j;
            if(k < j) break;
            tmp = sg[j]^sg[k];
            visit[tmp] = true;
        }
        for (int j = 0; j < 2010; j++){
            if(!visit[j]){
                sg[i] = j;
                break;
            }
        }
    }
    //for (int i = 0; i < 100; i++){
        //cout << "sg[i" << i << "] = " << sg[i] << endl;
    //}
    //cout << endl;
}

int main()
{
    getsg();
    while(~scanf("%d", &n)){
        if(sg[n] != 0)
            printf("1\n");
        else printf("2\n");
    }
    return 0;
}

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

int dis[][2] = {0,1, 1,0, -1,0, 0,-1, 1,1, -1,1, 1,-1, -1,-1};
bool inside(int a, int b){
    return a >= 0 && b >= 0 && a < 8 && b < 8;
}


int main()
{
    char ch1, ch2;
    ch1 = getchar();
    ch2 = getchar();
    int row = ch1-'a', col = ch2-'1', cnt = 0;
    for (int i = 0; i < 8; i++){
        int rn = row + dis[i][0], cn = col + dis[i][1];
        if(inside(rn, cn)) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}

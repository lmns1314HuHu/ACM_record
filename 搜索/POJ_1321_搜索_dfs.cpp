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

#define maxn 10

int n, k;
int cnt;
char grid[maxn][maxn];
bool row[maxn], column[maxn];

void dfs(int k, int x){
    if(k <= 0){
        cnt++; 
        return;
    }
    for (int i = x; i < n; i++){
        if(row[i]) continue;
        for (int j = 0; j < n; j++){
            if(column[j]) continue;
            if(grid[i][j] == '#'){
                row[i] = true; column[j] = true;
                dfs(k-1, i);
                row[i] = false; column[j] = false;
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n, &k)){
        if(n == -1 && k == -1) break;
        for (int i = 0; i < n; i++)
            scanf("%s", grid[i]);
        memset(row, 0, sizeof row);
        memset(column, 0, sizeof column);
        cnt = 0;
        dfs(k, 0);
        printf("%d\n", cnt);
    }
    return 0;
}

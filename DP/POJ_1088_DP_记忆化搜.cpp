#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int r, c;
int num[110][110];
int dp[110][110];
int dis[][2] = {-1, 0, 0, -1, 1, 0, 0, 1};

bool inside(int x, int y){
    return x >= 0 && y >= 0 && x < r && y < c;
}

int fun(int x, int y){
    if(dp[x][y] != 0)
        return dp[x][y];
    int ret = 0;
    for (int i = 0; i < 4; i++){
        int newx = x + dis[i][0], newy = y + dis[i][1];
        if(inside(newx, newy) && num[newx][newy] > num[x][y]){
            ret = max(ret, fun(newx, newy));
        }
    }
    dp[x][y] = ret + 1;
    return dp[x][y];
}

int main()
{
    while(~scanf("%d%d", &r, &c)){
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                scanf("%d", &num[i][j]);
            }
        }
        memset(dp, 0, sizeof dp);
        int res = 0;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                dp[i][j] = fun(i, j);
                if(dp[i][j] > res){
                    res = dp[i][j];
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

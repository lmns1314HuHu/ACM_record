#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

#define inf 0x3f3f3f3f
int dp[60000][11];
int dis[20][20];
int n, m, a, b, c;
int len[12];

//bool is(int num){
//    for (int i = 1; i <= n; i++){
//        int mod = pow(3, i);
//        if(num / (mod / 3) % 3 == 0)
//            return false;
//    }
//    return true;
//}

int shu(int zhuangtai, int num){
    return (zhuangtai / len[num]) % 3;
}

//char zhuan[20];
//int numtostring_jinzhi(int shu, char* str, int jinzhi){
//    int mod = jinzhi, i = 0;
//    while(shu){
//         str[i++] = (shu % mod) + '0';
//         shu /= jinzhi;
//    }
//    for (int j = i-1, k = 0; j > k; j--, k++){
//        int tmp = str[j];
//        str[j] = str[k];
//        str[k] = tmp;
//    }
//    str[i] = '\0';
//    return i;
//}

int main()
{
    len[0] = len[1] = 1;
    for (int i = 2; i <= 11; i++){
        len[i] = len[i-1]*3;
    }
    while(~scanf("%d%d", &n, &m)){
        memset(dis, inf, sizeof dis);
        memset(dp, inf, sizeof dp);
        for (int i = 0; i < m; i++){
            scanf("%d%d%d", &a, &b, &c);
            dis[a][b] = dis[b][a] = min(dis[a][b], c);
        }
        int res = inf;
        for (int i = 1; i <= n; i++){
            dp[len[i]][i] = 0;
        }
        for (int i = 1; i < len[n+1]; i++){
            bool flag = true;
            for (int j = 1; j <= n; j++){
                if(shu(i, j) != 0){
                    for(int v = 1; v <= n; v++){
                        if(shu(i, v) >= 2) continue;
                        dp[i+len[v]][v] = min(dp[i+len[v]][v], dp[i][j]+dis[j][v]);
                    }
                }
                else{
                    flag = false;
                }
            }
            if(flag){
                for (int j = 1; j <= n; j++){
                    res = min(res, dp[i][j]);
                }
            }
        }
        if(res == inf) printf("-1\n");
        else printf("%d\n", res);
    }
    return 0;
}

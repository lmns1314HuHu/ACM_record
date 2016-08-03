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
int n, m;

ll gcd(ll a, ll b){
    while(b != 0){
        ll tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

struct node{
    ll a, b;
};

char grid[55][55];
node dp[55][55];

int main()
{
    while(cin >> n >> m){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= i; j++){
                cin >> grid[i][j];
            }
        }
        memset(dp, 0, sizeof dp);
        node no, tmp;
        no.a = 1, no.b = 1;
        dp[1][1] = no;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= i; j++){
                no.a = dp[i][j].a;
                no.b = dp[i][j].b;
                if(no.b == 0) continue;
                if(grid[i][j] == '*'){
                    tmp.a = no.a;
                    tmp.b = no.b * 2;
                    ll g = gcd(tmp.a, tmp.b);
                    tmp.a /= g;
                    tmp.b /= g;

                    //dp[i+1][j]
                    if(dp[i+1][j].b == 0){
                        dp[i+1][j].a = tmp.a;
                        dp[i+1][j].b = tmp.b;
                    }
                    else{
                        g = gcd(dp[i+1][j].b, tmp.b);
                        ll l = dp[i+1][j].b / g * tmp.b;
                        dp[i+1][j].a = l / dp[i+1][j].b * dp[i+1][j].a + l / tmp.b * tmp.a;
                        dp[i+1][j].b = l;
                        g = gcd(dp[i+1][j].b, dp[i+1][j].a);
                        dp[i+1][j].b /= g;
                        dp[i+1][j].a /= g;
                    }

                    //dp[i+1][j+1]
                    if(dp[i+1][j+1].b == 0){
                        dp[i+1][j+1].a = tmp.a;
                        dp[i+1][j+1].b = tmp.b;
                    }
                    else{
                        g = gcd(dp[i+1][j+1].b, tmp.b);
                        ll l = dp[i+1][j+1].b / g * tmp.b;
                        dp[i+1][j+1].a = l / dp[i+1][j+1].b * dp[i+1][j+1].a + l / tmp.b * tmp.a;
                        dp[i+1][j+1].b = l;
                        g = gcd(dp[i+1][j+1].b, dp[i+1][j+1].a);
                        dp[i+1][j+1].b /= g;
                        dp[i+1][j+1].a /= g;
                    }
                }
                else if(grid[i][j] == '.'){
                    tmp.a = no.a;
                    tmp.b = no.b;
                    dp[i+2][j+1].a = tmp.a;
                    dp[i+2][j+1].b = tmp.b;
                }
            }
        }
        if(dp[n+1][m+1].b == 0)
            printf("0/1\n");
        else printf("%lld/%lld\n", dp[n+1][m+1].a, dp[n+1][m+1].b);
    }
    return 0;
}

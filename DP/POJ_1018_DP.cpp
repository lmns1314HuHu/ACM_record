#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;

int t, n, m;
int dp[120][1200];
struct node{
    int b, p;
}no[110];

bool cmp(node no1, node no2){
    if(no1.b == no2.b){
        return no1.p < no2.p;
    }
    return no1.b > no2.b;
}

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(dp, inf, sizeof dp);
        for (int i = 0; i < n; i++){
            scanf("%d", &m);
            for (int j = 0; j < m; j++){
                scanf("%d%d", &no[j].b, &no[j].p);
            }
            if(i == 0){
                for (int j = 0; j < m; j++){
                    dp[i][no[j].b] = no[j].p;
                }
            }
            else{
                for (int j = 0; j < m; j++){
                    for (int k = 0; k < 1200; k++){
                        if(dp[i-1][k] < inf){
                            int idx = min(k, no[j].b);
                            dp[i][idx] = min(dp[i][idx], dp[i-1][k] + no[j].p);
                        }
                    }
                }
            }
        }
        int resp = 0, resb = 0;
        for (int i = 0; i < 1200; i++){
            if(dp[n-1][i] < inf){
                if(resp == 0 && resb == 0){
                    resp = dp[n-1][i];
                    resb = i;
                }
                else{
            if(resb*i - dp[n-1][i]*resp < 0){
                        resp = dp[n-1][i];
                        resb = i;
                    }
                }
            }
        }
        printf("%.3lf\n", (double)resb/(double)resp);
    }
    return 0;
}
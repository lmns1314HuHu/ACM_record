#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, num[20];
int dp[1<<15];
int len[20];

int calc(int num){
    int cnt = 0;
    while(num != 0){
        if(num&1) cnt++;
        num >>= 1;
    }
    return cnt;
}

int main()
{
    len[0] = 1;
    for (int i = 1; i < 16; i++){
        len[i] = len[i-1]*2;
    }
    while(~scanf("%d", &n)){
        for (int i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }
        sort(num, num + n);
        memset(dp, 0, sizeof dp);
        int res = dp[0];
        for (int i = 0; i < len[n]; i++){
            if(calc(i)%3!=0)continue;
            for (int j = 0; j < n; j++){
                if((i>>j)&1)continue;
                for (int k = j + 1; k < n; k++){
                    if((i>>k)&1)continue;
                    for (int l = k + 1; l < n; l++){
                        if((i>>l)&1)continue;
                        if(num[j] + num[k] > num[l]){
                            int u = i + (1<<j) + (1<<k) + (1<<l);
                            dp[u] = max(dp[u], dp[i]+1);
                            res = max(res, dp[u]);
                        }
                    }
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

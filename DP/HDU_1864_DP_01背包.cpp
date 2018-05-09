#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int q, n, m, r;
int val[35];
int dp[3000010];

int main(){
    while(~scanf("%d.%d %d", &q, &r, &n)){
        if(n == 0) break;
        q *= 100;
        q += r;

        memset(val, 0, sizeof val);
        memset(dp, 0, sizeof dp);

        int idx = 0;
        int tot = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &m);
            int sum = 0, single, suma = 0, sumb = 0, sumc = 0;
            char tp;
            bool flag = false;
            for(int j = 0; j < m; j++){
                scanf(" %c:%d.%d", &tp, &single, &r);
                if(flag) continue;

                single *= 100;
                single += r;

                if(tp=='A') suma += single;
                else if(tp=='B') sumb += single;
                else if(tp=='C') sumc += single;
                else flag = true;

                if(suma > 60000 || sumb > 60000 || sumc > 60000) flag = true;
                sum += single;
                if(sum > 100000) flag = true;
            }
            if(!flag){
                tot += sum;
                val[idx++] = sum;
            }
        }

        if(tot <= q){
            printf("%d.", tot / 100);
            if(tot % 100 < 10){
                printf("0%d\n", tot % 100);
            }
            else{
                printf("%d\n", tot % 100);
            }
        }
        else{
            for(int i = 0; i < idx; i++){
                for (int j = q; j >= val[i]; j--){
                    dp[j] = max(dp[j], dp[j-val[i]]+val[i]);
                }
            }
            printf("%d.", dp[q] / 100);
            if(dp[q] % 100 < 10){
                printf("0%d\n", dp[q] % 100);
            }
            else{
                printf("%d\n", dp[q] % 100);
            }
        }
    }
    return 0;
}

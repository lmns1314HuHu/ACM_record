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
#include <vector>

using namespace std;
typedef long long ll;

int n;
char op[55];
ll num[55];
vector <int> v;
ll dp_max[55][55];
ll dp_min[55][55];

ll opt(ll num1, int b, ll num2){
    if(op[b] == 't')
        return num1 + num2;
    return num1*num2;
}

int main()
{
    while(~scanf("%d", &n)){
        v.clear();
        for (int i = 0; i < n; i++){
            getchar();
            scanf("%c %lld", &op[i], &num[i]);
        }
        for (int i = 0; i < n; i++){
            dp_max[i][i] = num[i];
            dp_min[i][i] = num[i];
        }
        int len;
        for (len = 1; len < n; len++){
            for (int i = 0; i < n; i++){
                int clk = 0;
                int ed = (i + len) % n;
                ll tmp_mx = -1000000000, tmp_mi = 1000000000;
                for (int j = i; clk < len; j = (j+1)%n, clk++){
                    ll tmp_res_max, tmp_res_min;
                    if(op[(j+1)%n] == 't'){
                        tmp_res_max = opt(dp_max[i][j], (j+1)%n, dp_max[(j+1)%n][ed]);
                        tmp_res_min = opt(dp_min[i][j], (j+1)%n, dp_min[(j+1)%n][ed]);
                    }
                    else{
                        ll res1 = opt(dp_max[i][j], (j+1)%n, dp_max[(j+1)%n][ed]);
                        ll res2 = opt(dp_max[i][j], (j+1)%n, dp_min[(j+1)%n][ed]);
                        ll res3 = opt(dp_min[i][j], (j+1)%n, dp_max[(j+1)%n][ed]);
                        ll res4 = opt(dp_min[i][j], (j+1)%n, dp_min[(j+1)%n][ed]);
                        tmp_res_max = max(res1, max(res2, max(res3, res4)));
                        tmp_res_min = min(res1, min(res2, min(res3, res4)));
                    }
                    if(tmp_mx < tmp_res_max) tmp_mx = tmp_res_max;
                    if(tmp_mi > tmp_res_min) tmp_mi = tmp_res_min;
                }
                dp_max[i][ed] = tmp_mx;
                dp_min[i][ed] = tmp_mi;
            }
        }

        ll mxans = -1000000000;
        for (int i = 0; i < n; i++){
            if(dp_max[i][(i+n-1)%n] > mxans){
                mxans = dp_max[i][(i+n-1)%n];
            }
        }
        for (int i = 0; i < n; i++){
            if(dp_max[i][(i+n-1)%n] == mxans){
                v.push_back(i);
            }
        }
        printf("%lld\n", mxans);
        for (int i = 0; i < v.size(); i++){
            printf("%d", v[i]+1);
            if(i != v.size()-1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}

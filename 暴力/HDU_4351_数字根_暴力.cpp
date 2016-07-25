#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

int t, n, q, a[100010];
int l, r, num;
bool dr[10];

int digit_root(ll num){
    return (int)((num-1)%9+1);
}

int main()
{
    scanf("%d", &t);
    for (int w = 1; w <= t; w++){
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            //a[i] = digit_root(num);
        }
        scanf("%d", &q);
        printf("Case #%d:\n", w);
        for(int y = 0; y < q; y++){
            scanf("%d%d", &l, &r);
            l--; r--;
            memset(dr, 0, sizeof dr);
            int cnt = 0;
            bool flag = false;
            for(int i = l; i <= r; i++){
                ll sum = 0;
                for (int j = i; j <= r; j++){
                    sum += a[j];
                    //cout << "sum=" << sum << " ";
                    int tmp = digit_root(sum);
                    if(dr[9]&&dr[8]&&dr[7]&&dr[6]&&dr[5]){
                        flag = true;
                        break;
                    }
                    if(!dr[tmp]){
                        dr[tmp] = true;
                        cnt++;
                    }
                }
                if(flag)
                    break;
            }
            int cc = 0;
            for (int i = 9; i>= 0; i--){
                if(cc == 5) break;
                if(dr[i]){
                    printf("%d", i);
                    cc++;
                    if(cc < 5)
                        printf(" ");
                    else 
                        printf("\n");
                }
            }
            for (int i = 0; i < 5-cc; i++){
                if(i < 4-cc) printf("-1 ");
                else printf("-1\n");
            }
        }
        if(w != t)
            printf("\n");
    }
    return 0;
}

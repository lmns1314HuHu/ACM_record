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

using namespace std;
typedef long long ll;

int t, n;
int num[100010];
int cha[100010];

int main()
{
    scanf("%d", &t);
    while(t--){
        int mx1 = -1, mx2 = -1, mx3 = -1;
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%d", &num[i]);
            if(i > 0)
                cha[i] = abs(num[i]-num[i-1]);
            if(cha[i] > mx1){
                mx3 = mx2;
                mx2 = mx1;
                mx1 = cha[i];
            }
            else if(cha[i] == mx1){
                mx3 = mx2;
                mx2 = mx1;
            }
            else if(cha[i] > mx2){
                mx3 = mx2;
                mx2 = cha[i];
            }
            else if(cha[i] == mx2){
                mx3 = mx2;
            }
            else if(cha[i] > mx3){
                mx3 = cha[i];
            }
        }
        //for (int i = 1; i <= n-1; i++){
            //cout << cha[i] << " ";
        //}
        //cout << endl;
        //cout << "mx1 = " << mx1 << endl;
        //cout << "mx2 = " << mx2 << endl;
        //cout << "mx3 = " << mx3 << endl;
        ll res = 0;
        //int kaishi = 0;
        for (int i = 0; i < n; i++){
            //kaishi = res;
            if(i == 0){
                int de = cha[1];
                if(de == mx1){
                    res += mx2;
                }
                else res += mx1;
            }
            else if(i == n-1){
                int de = cha[n-1];
                if(de == mx1)
                    res += mx2;
                else
                    res += mx1;
            }
            else{
                int tmp = abs(num[i-1] - num[i+1]);
                int zuo = cha[i];
                int you = cha[i+1];
                int maxdel = max(zuo, you);
                int mindel = min(zuo, you);
                if(maxdel == mx1){
                    if(mindel == mx2){
                        if(tmp > mx3){
                            res += tmp;
                        }
                        else{
                            res += mx3;
                        }
                    }
                    else{
                        if(tmp > mx2){
                            res += tmp;
                        }
                        else{
                            res += mx2;
                        }
                    }
                }
                else{
                    if(tmp > mx1){
                        res += tmp;
                    }
                    else{
                        res += mx1;
                    }
                }
            }
            //cout << res-kaishi << endl;
        }
        printf("%lld\n", res);
    }
    return 0;
}

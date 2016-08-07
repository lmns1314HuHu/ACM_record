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

using namespace std;
typedef long long ll;

int t, n;
int num[1000010];
int cnt;
ll sum;

int main()
{
    while(~scanf("%d", &n)){
        sum = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }
        int cnt = n;
        ll sum = 0;
        for (int i = n-1; i>= 0; i--){
            if(sum < 0){
                cnt--;
                sum += num[i];
            }
            else if(sum >= 0){
                sum = 0;
            }
            if(num[i] < 0 && sum == 0){
                sum += num[i];
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

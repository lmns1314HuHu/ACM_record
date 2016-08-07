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

int t, n, m, k;
int num[200010];

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }
        int zuo = 0, cnt = 0;
        ll res = 0;
        for (int i = 0; i < n; i++){
            if(num[i] >= m){
                cnt++;
            }
            while(cnt >= k){
                res += (n - i);
                if(num[zuo] >= m){
                    //cout << "hehe-";
                    cnt--;
                }
                zuo++;
            }
            //cout << cnt << endl;
        }
        printf("%lld\n", res);
    }
    return 0;
}

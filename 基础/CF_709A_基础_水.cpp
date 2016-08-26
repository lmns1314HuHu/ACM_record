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
#include <cmath>

using namespace std;
typedef long long ll;

int n, b, d;
int num;

int main()
{
    scanf("%d%d%d", &n, &b, &d);
    int cnt = 0;
    ll res = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &num);
        if(num > b) continue;
        res += num;
        if(res > d){
            res = 0;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

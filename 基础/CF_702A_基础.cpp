/**==================================
 | Author: YunHao
 | OJ: CF
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

int n;
int rem;
int num;

int main()
{
    while(~scanf("%d", &n)){
        rem = -1;
        int res = 1, tmp = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &num);
            if(num > rem){
                tmp++;
            }
            else{
                if(tmp > res)
                    res = tmp;
                tmp = 1;
            }
            rem = num;
        }
        if(tmp > res)
            res = tmp;
        printf("%d\n", res);
    }
    return 0;
}

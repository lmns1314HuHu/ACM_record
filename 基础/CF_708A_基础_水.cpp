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

#define maxn 100010
char st[maxn];

int main()
{
    scanf("%s", st);
    int len = strlen(st);
    bool flag = false;
    for(int i = 0; i < len; i++){
        if(st[i] != 'a'){
            st[i]--;
            flag = true;
        }
        else{
            if(flag) break;
        }
    }
    if(!flag) st[len-1] = 'z';
    printf("%s\n", st);
    return 0;
}

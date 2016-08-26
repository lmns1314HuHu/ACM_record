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

int num[300010];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    sort(num, num + n);
    int l = 0, r = n-1;
    while(l < r){
        int mid = (l+r)>>1;
        int midmid = (mid + r)>>1;
        if(midmid == mid) midmid = mid+1;
        ll res1 = 0, res2 = 0;
        for (int i = 0; i < n; i++){
            res1 += abs(num[i] - num[mid]);
            res2 += abs(num[i] - num[midmid]);
        }
        if(res1 <= res2) r = midmid - 1;
        else l = mid + 1;
    }
    printf("%d\n", num[l]);
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int a[10010];

bool issame(int k){
    if(a[k] != a[k+1])
        return false;
    else if(a[k+1] != a[k+2])
        return false;
    else if(a[k+2] != a[k+3])
        return false;
    return true;
}

bool can(int k){
    if(a[k]+a[k+1]+a[k+2] > a[k+3])
        return true;
    return false;
}

int main()
{
    while(~scanf("%d", &n)){
        for (int i = 0; i < n; i++){
            scanf("%d", a+i);
        }
        sort(a, a+n);
        int ans = -1;
        for (int i = 0; i <= n-4; i++){
            if(issame(i)) continue;
            if(can(i)){
                if(a[i]+a[i+1]+a[i+2]+a[i+3] > ans)
                    ans = a[i]+a[i+1]+a[i+2]+a[i+3];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

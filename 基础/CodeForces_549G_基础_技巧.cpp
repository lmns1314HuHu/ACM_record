#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[200010];

int main()
{
    while(~scanf("%d", &n)){
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        a[i] -= (n-i-1);
    }
    sort(a, a+n);
    bool flag = false;
    for (int i = 0; i < n-1; i++){
        if(a[i] == a[i+1]){
            flag = true;
        }
    }
    if(flag)
        printf(":(\n");
    else{
        for (int i = 0; i < n-1; i++){
            printf("%d ", a[i]+n-1-i);
        }
        printf("%d\n", a[n-1]);
    }
    }
    return 0;
}

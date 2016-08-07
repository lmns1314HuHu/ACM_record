#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
int p, n, k;
//ll num;

int main()
{
    scanf("%d", &p);
    while(p--){
        scanf("%d%d", &k, &n);
        ll res = 0;
        for (int i = 1; i <= n; i++){
            res += i;
        }
        if(n % 2 == 1)
        printf("%d %lld %lld %lld\n", k, res, res + (n/2)*n, res + (n/2)*n+n);
        else {
            printf("%d %lld %lld %lld\n", k, res, res + (n/2)*(n-1), res+(n/2)*(n+1));
            }
    }
    return 0;
}

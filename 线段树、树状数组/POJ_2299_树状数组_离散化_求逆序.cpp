#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define LEN 510000
int e[LEN];
int a[LEN];
int n;
//li san hua
struct discre{
    int v, ord;
}p[510000];

bool cmp(discre d1, discre d2){
    return d1.v < d2.v;
}

void lisanhua(int n){
    sort(p, p + n, cmp);
    for (int i = 0; i < n; i++)
        a[p[i].ord] = i;
}

int lowbit(int k){
    return k&-k;
}

void add(int k, int v){
    while(k < LEN){
        e[k] += v;
        k += lowbit(k);
    }
}

int sum(int k){
    int re = 0;
    while(k > 0){
        re += e[k];
        k -= lowbit(k);
    }
    return re;
}

int main()
{
    while(scanf("%d", &n), n){
        memset(e, 0, sizeof(e));
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            p[i].v = a[i];
            p[i].ord = i;
        }
        lisanhua(n);

        long long ans = 0;
        for (int i = 0; i < n; i++){
            ans += sum(n-a[i]);
            add(n-a[i], 1);
        }
        printf("%lld\n", ans);

    }
    return 0;
}

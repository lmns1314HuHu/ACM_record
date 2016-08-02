#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

int cnt[220];
int t, n;

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(cnt, 0, sizeof cnt);
        int ans = 0;
        for (int i = 0; i < n; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            if(a > b)swap(a, b);
            int x = (a + 1) / 2, y = (b + 1) / 2;
            for (int j = x; j <= y; j++){
                cnt[j]++;
                if(cnt[j] > ans){
                    ans = cnt[j];
                }
            }
        }
        printf("%d\n", ans * 10);
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

int cnt[5010];
int n, m, t;
int num[100010];
int sum[100010];

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        memset(sum, 0, sizeof sum);
        memset(cnt, 0, sizeof (cnt));
        bool flag = false;
        for (int i = 1; i <= n; i++){
            scanf("%d", &num[i]);
            sum[i] = sum[i-1]+num[i];
            int v = sum[i] % m;
            if(cnt[v] != 0){
                flag = true;
            }
            cnt[v]++;
        }
	if(cnt[0] >= 1)flag = true;
        if(flag){
            printf("YES\n");
        }
        else 
            printf("NO\n");
    }
    return 0;
}

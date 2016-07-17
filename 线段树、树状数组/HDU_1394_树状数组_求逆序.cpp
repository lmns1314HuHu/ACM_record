#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define LEN 5010
int e[LEN];
int n;
int num[5010];

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
    while(~scanf("%d", &n)){
        memset(e, 0, sizeof(e));

        int cnt = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &num[i]);
            cnt += sum(n - num[i]);
            add(n-num[i], 1);
        }

        //tmp lin shi bao cun mei zu pai lie de ni xu shu
        int ans = cnt, tmp;
        for (int i = 0; i < n; i++){
            add(n-num[i], -1);
            cnt = cnt + sum(n-num[i]) - num[i];
            add(n-num[i], 1);
            if(ans > cnt) ans = cnt;
        }
        printf("%d\n", ans);
    }
    return 0;
}

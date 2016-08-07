#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t;
int n, m;
int num[50];

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        int i, cnt = 0;
        for (i = 0; n; i++){
            num[i] = n%2;
            cnt += (n%2);
            n /= 2;
        }
        if(i <= m){
            printf("%d\n", cnt);
            continue;
        }
        int jishu = 0;
        for (int j = i-1; j > m; j--){
            jishu += num[j];
            jishu *= 2;
            cnt -= num[j];
        }
        printf("%d\n", jishu+cnt);
        
    }
    return 0;
}

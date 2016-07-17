#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int lowbit(int k){
    return k&-k;
}

#define LEN 50010

int t;
int n;
char s[10];
int num[50010];
int a, b;
int e[LEN];

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
    scanf("%d", &t);
    for(int w = 1; w <= t; w++){
        printf("Case %d:\n", w);
        scanf("%d", &n);
        memset(e, 0, sizeof(e));

        for (int i = 1; i <= n; i++){
            scanf("%d", &num[i]);
            add(i, num[i]);
        }
        while(scanf("%s", s)){
            if(s[0] == 'E') break;
            scanf("%d%d", &a, &b);
            if(s[0] == 'Q'){
                printf("%d\n", sum(b) - sum(a-1));
            }
            else if(s[0] == 'A'){
                add(a, b);
            }
            else if(s[0] == 'S'){
                add(a, -1*b);
            }
        }
    }
    return 0;
}

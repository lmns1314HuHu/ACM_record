#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int num[110];
int a;

int main()
{
    while(~scanf("%d", &a)){
        memset(num, 0, sizeof num);
        int sum = a;
        num[a] += a;
        for (int i = 1; i < 5; i++){
            scanf("%d", &a);
            num[a] += a;
            sum += a;
        }
        int index = 0;
        int maxnum = 0;
        for (int i = 1; i < 101; i++){
            if(num[i] != i){
                if(num[i] > i*3) num[i] = i*3;
                if(num[i] > maxnum){
                    maxnum = num[i];
                    index = i;
                }
            }
        }
        printf("%d\n", sum - maxnum);
    }
    return 0;
}

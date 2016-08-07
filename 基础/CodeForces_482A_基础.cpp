#include <iostream>
#include <cstdio>
using namespace std;

int n, k;

int main()
{
    while(~scanf("%d%d", &n, &k)){
        printf("1");
        int cnt = 0;
        int da = n, xiao = 2;
        for (int i = 0; i < n; i++){
            if(cnt >= k-1) break;
            if(i % 2 == 0)
                printf(" %d", da--);
            else printf(" %d", xiao++);
            cnt++;
        }
        if(k % 2 == 0){
            while(da >= xiao)
                printf(" %d", da--);
        }
        else {
            while(xiao <= da)
                    printf(" %d",xiao++);
        }
        printf("\n");
    }
    return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

int k, num[10010];

int main(){
    while(~scanf("%d", &k), k){
        int cnt = 0;
        for (int i = 0; i < k; i++){
            scanf("%d", &num[i]);
            if(num[i] < 0){
                cnt++;
            }
        }
        if(cnt == k){
            printf("0 %d %d\n", num[0], num[k-1]);
            continue;
        }
        int sum = 0;
        int mx = -1;
        int resl = 0, resr = -1;
        int l = 0, r = -1;
        for(int i = 0; i < k; i++){
            r = i;
            sum += num[i];
            if(sum < 0){
                sum = 0;
                l = i+1;
            }
            else{
                if(sum > mx){
                    mx = sum;
                    resl = l;
                    resr = r;
                }
            }
        }
        printf("%d %d %d\n", mx, num[resl], num[resr]);
    }
    return 0;
}

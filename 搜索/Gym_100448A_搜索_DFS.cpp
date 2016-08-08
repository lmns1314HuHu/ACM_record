#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int mx;
int cun[10];
int b[10];
int n;

int numtoarray(int num, int* ret){
    memset(ret, 0, sizeof(ret));
    if(num == 0) return 1;
    int i;
    for (i = 0; num != 0; i++){
        ret[i] = num % 10;
        num /= 10;
    }
    for(int j = 0, k = i - 1; j < k; j++, k--){
        int temp = ret[j];
        ret[j] = ret[k];
        ret[k] = temp;
    }
    return i;
}

//int cntwei(int num){
//    if(num == 0) return 1;
//    int i;
//    for (i = 0; num != 0; i++){
//        num /= 10;
//    }
//    return i;
//}

int arraytonum(int* ret, int wei){
    int ans = 0;
    for (int i = 0; i < wei; i++){
        ans *= 10;
        ans += ret[i];
    }
    return ans;
}

void dfs(int num, int k){
    if(k >= n) return;
    num += b[k];
    int shu[10];
    int wei = numtoarray(num, shu);
    sort(shu, shu + wei);
    do{
        int numnew = arraytonum(shu, wei);
        if(numnew > mx) mx = numnew;
        dfs(numnew, k+1);
    }
    while(next_permutation(shu, shu + wei));
}

int main()
{
    while(~scanf("%d", &n)){
        mx = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &b[i]);
        }
        dfs(0, 0);
        printf("%d\n", mx);
    }
    return 0;
}

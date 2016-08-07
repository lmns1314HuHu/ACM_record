#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n;
long long num[110][110];
long long sum;

int main()
{
    while(~scanf("%d", &n)){
        sum = 0;
        for (int i = 0; i < n; i++){
            long long he = 0;
            for (int j = 0; j < n; j++){
                scanf("%I64d", &num[i][j]);
                he += num[i][j];
            }
            sum += he;
            num[i][109] = he;
        }
        sum = sum / (n-1);
//        cout << sum << endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(num[i][j] == 0){
                    printf("%I64d", sum - num[i][109]);
                }
                else printf("%I64d", num[i][j]);
                if(j != n-1) printf(" ");
                else printf("\n");
            }
        }
    }
    return 0;
}

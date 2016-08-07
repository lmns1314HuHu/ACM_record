#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int t;
int n;
#define maxn 100005
int num[maxn];
//int _len[maxn];
int dp[maxn];

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }
        int len = 0;
        for (int i = 0; i < n; i++){
            int low = 0;
            int high = len - 1;
            while(low <= high){
                int mid = (low + high) >> 1;
                if(dp[mid] < num[i])
                    low = mid + 1;
                else 
                    high = mid-1;
            }
            if(low >= len) len++;
            dp[low] = num[i];
            //_len[i] = low+1;

            printf("%d", low+1);
            if(i < n-1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}

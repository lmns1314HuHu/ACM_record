#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
#define maxn 100005
int num[maxn];
int dp[maxn];

int main()
{
    while(~scanf("%d", &n)){
        for (int i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }
        int len = 0;
        for (int i = 0; i < n; i++){
            int low = 0;
            int high = len - 1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(dp[mid] < num[i])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            if(low >= len) len++;
            dp[low] = num[i];
        }
        printf("%d\n", len);
    }
    return 0;
}

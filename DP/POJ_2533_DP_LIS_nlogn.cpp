#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[10009];
int num[1005];
int n;

//longest increasing sequence
//nlogn
int main()
{
    while(~scanf("%d", &n)){
        for (int i = 0; i < n; i++){
            scanf("%d", num+i);
        }
        int len = 0;
        //dp[0] = 0;
        for (int i = 0; i < n; i++){
            int low = 0, high = len-1;
            while(low <= high){
                int mid = (low + high)/2;
                if(dp[mid] < num[i])
                    low = mid+1;
                else
                    high = mid-1;
            }

            if(low >= len) len++;

            dp[low] = num[i];

//            cout << i << ": ";
//            for (int j = 0; j < len; j++){
//                cout << dp[j] << " ";
//            }
//            cout << "low=" << low <<endl;
        }
        printf("%d\n", len);
    }
    return 0;
}

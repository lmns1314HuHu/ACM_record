#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int p, k, n;
int dp[10005];

int main()
{
	scanf("%d", &p);
		dp[0] = 0;
		dp[1] = 2;
		for (int i = 2; i <= 10000; i++){
			dp[i] = dp[i-1];
			dp[i] += i-1;
			for (int j = 2; j <= i / 2; j++){
				if(i % j == 0){
					dp[i] -= dp[j];
					dp[i] += dp[j-1];
				}
			}
		}
	while(p--){
		scanf("%d%d", &k, &n);
		printf("%d %d\n", k, dp[n]);
	}
	return 0;
}
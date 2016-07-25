#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
typedef long long ll;

int main()
{
	while(~scanf("%d", &n)){
		ll res = 0;
		for (int i = 1; i <= n; i++){
			res += i;
		}
		printf("%lld\n\n", res);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
int n;
ll num;

int main()
{
	while(~scanf("%d", &n)){
		ll res = 1;
		for (int i = 0; i < n; i++){
			scanf("%lld", &num);
			ll gcd = __gcd(num, res);
			res = res / gcd * num;
		}
		printf("%lld\n", res);
	}
	return 0;
}
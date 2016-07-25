#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
typedef long long ll;

int t, n;
ll num;

ll gcd(ll a, ll b){
	while(b != 0){
		ll tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}

int main()
{
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf("%d", &num);
		ll res = num;
		for (int i = 1; i < n; i++){
			scanf("%d", &num);
			ll tmp = gcd(res, num);
			res = res / tmp * num;
		}
		printf("%lld\n", res);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

int p, k, n;

ll C_nm(int n, int  m){
	if(m > n/2) m=n-m;
	ll res = 1;
	for (int i = 0; i < m; i++){
		res = res * (n-i) / (i+1);
	}
	return res;
}

int main()
{
	scanf("%d", &p);
	while(p--){
		scanf("%d%d", &k, &n);
		int twos = n/4*2;
		int ones = n-twos*2;
		ll ans = 0;
		while(twos >= ones){
			ll tmp = C_nm((twos+ones)/2, ones/2);
			ans += (ll)(tmp*tmp);
			twos -= 2;
			ones += 4;
		}
		printf("%d %lld\n", k, ans);
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		if(n > m) swap(n, m);
		ll odd = 0;
		ll even = 0;
		for (int i = n; i <= m; i++){
			if(i&1)odd += (i*i*i);
			else even += (i*i);
		}
		printf("%lld %lld\n", even, odd);
	}
	return 0;
}
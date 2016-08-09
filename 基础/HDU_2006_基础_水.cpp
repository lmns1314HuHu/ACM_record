#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

int main()
{
	int n, num;
	while(~scanf("%d", &n)){
		ll res = 1;
		for (int i = 0; i < n; i++){
			scanf("%d", &num);
			if(num&1)
				res *= num;
		}
		printf("%lld\n", res);
	}
	return 0;
}
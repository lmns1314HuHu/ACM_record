#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
int a, num[2];

int main()
{
	while(scanf("%d", &a), a){
		num[0] = num[1] = 0;
		ll res = 0;
		for (int i = 1; i <= a; i++){
			scanf("%d", &num[i%2]);
			res += 5;
			if(num[i%2] > num[(i-1)%2]){
				res += (num[i%2] - num[(i-1)%2])*6;
			}
			else{
				res -= (num[i%2] - num[(i-1)%2])*4;;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
ll n;
char st[1000000];

int main()
{
	while(~scanf("%s", st)){
		if(st[0] == '0') break;
		int len = strlen(st);
		ll res = 0;
		for (int i = 0; i < len; i++){
			res += st[i]-'0';
		}
		printf("%lld\n", (res-1)%9+1);
	}
	return 0;
}
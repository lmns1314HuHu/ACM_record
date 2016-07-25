#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
ll a, b;

ll gcd(ll a, ll b){
	while(b != 0){
		ll temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}

int main()
{
	while(~scanf("%lld%lld", &a, &b)){
		printf("%10lld%10lld    ", a, b);
		if(gcd(a, b) == 1){
			printf("Good Choice\n");
		}
		else printf("Bad Choice\n");
		printf("\n");
	}
	return 0;
}
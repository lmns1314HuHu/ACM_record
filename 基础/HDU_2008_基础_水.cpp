#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int n;
	double num;
	while(~scanf("%d", &n) && n){
		int pos = 0;
		int neg = 0;
		int zero = 0;
		for (int i = 0; i < n; i++){
			scanf("%lf", &num);
			if(num > 0)pos++;
			else if(num == 0) zero++;
			else neg++;
		}
		printf("%d %d %d\n", neg, zero, pos);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		double res = 0;
		for (int i = 1; i <= n; i++){
			if(i&1) res += ((double)(1.0/(double)i));
			else res -= ((double)((1.0)/(double)i));
		}
		printf("%.2lf\n", res);
	}
	return 0;
}
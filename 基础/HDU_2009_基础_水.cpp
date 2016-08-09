#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		double res = n;
		double tmp = n;
		for (int i = 0; i < m-1; i++){
			res += (tmp = sqrt(tmp));
		}
		printf("%.2lf\n", res);
	}
	return 0;
}
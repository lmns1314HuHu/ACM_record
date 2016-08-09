#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	double r;
	while(~scanf("%lf", &r)){
		printf("%.2lf\n", abs(r));
	}
	return 0;
}
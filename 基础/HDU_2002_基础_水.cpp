#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define Pi 3.1415927

int main()
{
	double r;
	while(~scanf("%lf", &r)){
		printf("%.3lf\n", 4.0/3.0*Pi*r*r*r);
	}
	return 0;
}
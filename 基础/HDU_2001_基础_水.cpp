#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	double x1, x2, y1, y2;
	while(~scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2)){
		printf("%.2lf\n", (double)(sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))));
	}
	return 0;
}
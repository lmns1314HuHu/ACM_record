#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

double e;

int main()
{
	double jie = 6;
	double he = 2.666666666666666666;
	printf("n e\n- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for (int i = 3; i <= 9; i++){
		printf("%d %.9lf\n", i, (double)he);
		jie *= (i+1);
		he += (1.0/jie);
	}
	return 0;
}
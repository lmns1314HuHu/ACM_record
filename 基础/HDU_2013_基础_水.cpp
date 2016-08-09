#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int n;
	while(~scanf("%d", &n)){
		double sum = 0;
		int mx = -1;
		int mi = 10000;
		int num;
		for (int i = 0; i < n; i++){
			scanf("%d", &num);
			if(num > mx) mx = num;
			if(num < mi) mi = num;
			sum += num;
		}
		printf("%.2lf\n", (double)(sum-mx-mi)/(double)(n-2));
	}
	return 0;
}
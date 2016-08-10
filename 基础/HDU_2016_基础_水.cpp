#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int num[110];

int main()
{
	while(~scanf("%d", &n) && n){
		scanf("%d", &num[0]);
		int mi = num[0];
		int mi_idx = 0;
		for (int i = 1; i < n; i++){
			scanf("%d", &num[i]);
			if(num[i] < mi){
				mi = num[i];
				mi_idx = i;
			}
		}
		num[mi_idx] = num[0];
		num[0] = mi;
		for (int i = 0; i < n; i++){
			printf("%d", num[i]);
			if(i != n-1)printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int num[110];

int main()
{
	for (int i = 1; i <= 100; i++)
		num[i] = 2*i;
	int n, m;
	while(~scanf("%d %d", &n, &m)){
		int cnt = 0;
		int sum = 0;
		bool flag = false;
		for (int i = 1; i <= n; i++){
			if(cnt == m){
				if(flag) printf(" ");
				cnt = 0;
				printf("%d", sum / m);
				sum = 0;
				flag = true;
			}
			cnt++;
			sum += num[i];
		}
		if(cnt != 0){
			if(flag) printf(" ");
			printf("%d", sum / cnt);
		}
		printf("\n");
	}
	return 0;
}
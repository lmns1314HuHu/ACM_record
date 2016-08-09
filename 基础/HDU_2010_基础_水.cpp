#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

bool isshuixianhua(int num){
	int tmp = num;
	int res = 0;
	for (int i = 0; i < 3; i++){
		res += (pow(tmp%10, 3));
		tmp /= 10;
	}
	return res == num;
}

int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		if(n > m) swap(n, m);
		bool flag = false;
		for (int i = n; i <= m; i++){
			if(isshuixianhua(i)){
				if(flag) printf(" ");
				printf("%d", i);
				flag = true;
			}
		}
		if(!flag) printf("no");
		printf("\n");
	}
	return 0;
}
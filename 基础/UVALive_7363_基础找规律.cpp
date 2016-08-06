#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int p, n1,n2, k;
int num[1010];

int main()
{
	scanf("%d", &p);
	while(p--){
		scanf("%d %d/%d", &k, &n1, &n2);
		int cnt = 0;
		while(n1 != n2){
			if(n1 > n2){
				n1 -= n2;
				num[cnt] = 1;
			}
			else{
				n2 -= n1;
				num[cnt] = 0;
			}
			cnt++;
		}
		int res = (int)pow(2, cnt)-1;
		int zuoce = 0;
		for (int i = cnt-1; i >= 0; i--){
			zuoce *= 2;
			zuoce += num[i];
		}
		res += zuoce+1;
		printf("%d %d\n",k, res);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n;
int num;

int main()
{
	while(~scanf("%d", &n) && n){
		int cnt = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &num);
			cnt += (num / 100);
			num %= 100;
			cnt += (num / 50);
			num %= 50;
			cnt += (num / 10);
			num %= 10;
			cnt += (num / 5);
			num %= 5;
			cnt += (num / 2);
			num %= 2;
			cnt += (num);
		}
		printf("%d\n", cnt);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int num1, num2;
int res1, res2;

int main()
{
	while(~scanf("%d", &n)){
		res1 = res2 = 0;
		for (int i = 0; i < n; i++){
			scanf("%d%d", &num1, &num2);
			if(num1 > num2) res1 ++;
			else if(num1 < num2) res2 ++;
		}
		if(res1 > res2) printf("Mishka\n");
		else if(res1 < res2) printf("Chris\n");
		else printf("Friendship is magic!^^\n");
	}
	return 0;
}

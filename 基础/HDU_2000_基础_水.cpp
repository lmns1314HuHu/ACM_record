#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char c1[3];

int main()
{
	while(~scanf("%c%c%c", &c1[0], &c1[1], &c1[2])){
		getchar();
		sort(c1, c1+3);
		printf("%c %c %c\n", c1[0], c1[1], c1[2]);
	}
	return 0;
}
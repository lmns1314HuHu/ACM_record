#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[110];

int main()
{
	while(~scanf("%s", s)){
		char ch = getchar();
		printf("%c", toupper(s[0]));
		printf("%s", s+1);
		printf("%c", ch);
	}
	return 0;
}
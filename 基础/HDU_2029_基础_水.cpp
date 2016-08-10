#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
char s[110];

int main()
{
	scanf("%d", &n);
	getchar();
	while(n--){
		scanf("%s", s);
		int len = strlen(s);
		bool flag = true;
		for (int i = 0, j = len-1; i < j; i++, j--){
			if(s[i] != s[j]){
				flag = false;
				break;
			}
		}
		if(flag) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
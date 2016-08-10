#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
char s[1000000];

int main()
{
	scanf("%d", &n);
	getchar();
	while(n--){
		int cnt = 0;
		while(scanf("%s", s)){
			char ch = getchar();
			int len = strlen(s);
			for (int i = 0; i < len; i++){
				if(s[i] < 0)
					cnt++;
			}
			if(ch == '\n') break;
		}
		printf("%d\n", cnt / 2);
	}
	return 0;
}
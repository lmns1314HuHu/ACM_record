#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[110];
int num[5];

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	while(n--){
		memset(num, 0, sizeof num);
		while(scanf("%s", s)){
			char ch = getchar();
			int len = strlen(s);
			for(int i = 0; i < len; i++){
				if(s[i] == 'a') num[0]++;
				else if(s[i] == 'e') num[1]++;
				else if(s[i] == 'i') num[2]++;
				else if(s[i] == 'o') num[3]++;
				else if(s[i] == 'u') num[4]++;
			}
			if (ch == '\n') break;
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", num[0], num[1], num[2], num[3], num[4]);
		if(n != 0) printf("\n");
	}
	return 0;
}
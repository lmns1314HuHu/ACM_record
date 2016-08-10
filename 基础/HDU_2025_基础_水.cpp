#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char st[110];

int main()
{
	while(gets(st)){
		int len = strlen(st);
		char mx = st[0];
		for (int i = 0; i < len; i++){
			if(mx < st[i]){
				mx = st[i];
			}
		}
		for (int i = 0; i < len; i++){
			printf("%c", st[i]);
			if(st[i] == mx){
				printf("(max)");
			}
		}
		printf("\n");
	}
	return 0;
}
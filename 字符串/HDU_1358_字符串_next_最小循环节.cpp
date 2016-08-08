#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
char st[1000010];
int nxt[1000010];

void getnext(){
	nxt[0] = -1;
	int i = 0, j = -1;
	while(i <= n){
		while(j >= 0 && st[i] != st[j])
			j = nxt[j];
		j++;i++;
		nxt[i] = j;
	}
}

int main()
{
	int w = 1;
	while(scanf("%d", &n), n){
		getchar();
		scanf("%s", st);
		getnext();
		printf("Test case #%d\n", w++);
		for (int i = 2; i <= n; i++){
			if(i % (i - nxt[i]) == 0){
				int res = i / (i-nxt[i]);
				if(res <= 1) continue;
				printf("%d %d\n", i, res);
			}
		}
		printf("\n");
	}
	return 0;
}

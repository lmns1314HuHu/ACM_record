#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, t;
int e[50010];
char _cmd[10];
int x, y;

int lowbit(int k){
	return k&-k;
}

void add(int k, int v){
	while(k <= n){
		e[k] += v;
		k += lowbit(k);
	}
}

int sum(int k){
	int re = 0;
	while(k > 0){
		re += e[k];
		k -= lowbit(k);
	}
	return re;
}

int main()
{
	scanf("%d", &t);
	for (int w = 1; w <= t; w++){
		scanf("%d", &n);
		memset(e, 0, sizeof e);
		for (int i = 1; i <= n; i++){
			scanf("%d", &x);
			add(i, x);
		}
		printf("Case %d:\n", w);
		while(~scanf("%s", _cmd)){
			if(_cmd[0] == 'Q'){
				scanf("%d%d", &x, &y);
				printf("%d\n", sum(y) - sum(x-1));
			}
			else if(_cmd[0] == 'A'){
				scanf("%d%d", &x, &y);
				add(x, y);
			}
			else if(_cmd[0] == 'S'){
				scanf("%d%d", &x, &y);
				add(x, -1*y);
			}
			else if(_cmd[0] == 'E')
				break;
		}
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
bool visit[22];
int num[20];

bool isPrime(int num){
    if(num < 2) return false;
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

void dfs(int u, int dep){
	if(visit[u]) return;
	num[dep] = u;
	if(dep == n && isPrime(u+1)){
		for (int i = 1; i <= n; i++){
			printf("%d", num[i]);
			if(i != n)printf(" ");
			else printf("\n");
		}
		return;
	}
	visit[u] = true;
	for (int i = 2; i <= n; i++){
		if(visit[i]) continue;
		if(isPrime(u+i)){
			dfs(i, dep+1);
		}
	}
	visit[u] = false;
}

int main()
{
	int w = 1;
	while(~scanf("%d", &n)){
		printf("Case %d:\n", w++);
		memset(visit, 0, sizeof visit);
		dfs(1, 1);
		printf("\n");
	}
	return 0;
}
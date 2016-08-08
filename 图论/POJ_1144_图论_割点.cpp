#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
int x, y;
vector<int> V[110];
int depth, root_cnt, dfn[110];
bool fg[110];
int total;
int low[110];

void init(){
	depth = 0;
	root_cnt = 0;
	memset(dfn, -1, sizeof dfn);
	memset(fg, 0, sizeof fg);
}

void dfs(int u, int fa){
	int i, v;
	dfn[u] = low[u] = depth++;
	for (i = 0; i < V[u].size(); i++){
		v = V[u][i];
		if(dfn[v] == -1){
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(u == 1) root_cnt++;
			else if(low[v] >= dfn[u] && !fg[u]){
				fg[u] = 1;
				total++;
			}
		}
		else if(v != fa)
			low[u] = min(low[u], dfn[v]);
	}
}

int main()
{
	while(scanf("%d", &n), n){
		for (int i = 0; i <= n; i++) V[i].clear();
		while(scanf("%d", &x), x){
			while(getchar() != '\n'){
				scanf("%d", &y);
				V[x].push_back(y);
				V[y].push_back(x);
			}
		}
		total = 0;
		init();
		dfs(1, -1);
		if(root_cnt > 1) total++;
		printf("%d\n", total);
	}
	return 0;
}

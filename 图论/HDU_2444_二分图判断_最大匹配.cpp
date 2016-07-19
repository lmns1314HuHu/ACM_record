#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m, a, b;
vector<int> V[220];
int _map[220][220];
bool check[220];
int matching[220];
int col[220];
queue<int> q;

//涂色法判断是否是二分图
bool is(int s){
	while(q.size()) q.pop();
	q.push(s);
	col[s] = 0;
	while(!q.empty() ){
		int u = q.front();
		q.pop();
		for (int i = 1; i <= n; i++ ) {
			if(_map[u][i] && col[i] == col[u] ) return false;
			if(_map[u][i] && col[i] == -1 ){
				col[i] = col[u]^1;
				q.push(i);
			}
		}
	}
	return true;
}

bool dfs(int u){
	for (int v = 1; v <= n; v++ ){
		if(_map[u][v] && !check[v] ){
			check[v] = true;
			if(matching[v] == -1 || dfs(matching[v] ) ){
				matching[v] = u;
				return true;
			}
		}
	}
	return false;
}

int hangary(int n_left){
	int res = 0;
	memset(matching, -1, sizeof(matching));
	for (int i = 1; i <= n_left; i++ ){
		memset(check, false, sizeof(check) );
		if(dfs(i)) res++;
	}
	return res;
}

int main()
{
	while(~scanf("%d%d", &n, &m)){
		for (int i = 0; i <= n; i++){
			V[i].clear();
		}
		memset(_map, 0, sizeof _map );
		int s = -1;
		for (int i = 0; i < m; i++){
			scanf("%d%d", &a, &b );
			_map[a][b] = _map[b][a] = 1;
			s = a;
		}
		
		bool flag = true;
		memset ( col, -1, sizeof col );
		for(int i = 1; i <= n; i++ ){ //因为有可能有多个联通分量，所以要遍历每个点
			if( col[i] == -1 ){
				flag = is( i );
				if( flag == false ) break;
			}
		}
		
		if( flag ){
			printf("%d\n", hangary(n) / 2 );
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}

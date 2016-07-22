#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int n, m, x, y;
int _map[550][550];
int rudu[550];
priority_queue<int, vector<int>, greater<int> > q;
bool visit[550];

int main()
{
	while(~scanf("%d%d", &n, &m)){
		memset(_map, 0, sizeof (_map));
		memset(rudu, 0, sizeof (rudu));
		memset(visit, 0, sizeof(visit));
		for ( int i = 0; i < m; i++){
			scanf("%d%d", &x, &y);
			if(_map[x][y]) continue;//you chong bian, xu yao pan chong.
			_map[x][y] = 1;
			rudu[y]++;
		}
		while(q.size()) q.pop();
		for (int i = 1; i <= n; i++){
			if(rudu[i] == 0){
				q.push(i);
			}
		}
		int cnt = 1;
		while(!q.empty()){
			int u = q.top();
			visit[u] = 1;
			q.pop();
			printf("%d", u);
			if(cnt++ == n) printf("\n");
			else printf(" ");
			for (int i = 1; i <= n; i++){
				if(_map[u][i]) rudu[i]--;
				if(_map[u][i] && rudu[i] == 0) 
					q.push(i);
			}
		}
		for (int i = 1; i <= n; i++){
			if(!visit[i]){
				printf("%d", i);
				if(cnt++ == n) printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}

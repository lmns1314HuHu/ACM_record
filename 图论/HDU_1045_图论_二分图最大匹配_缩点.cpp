#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n;
char _grid[10][10];
int _row[10][10];//该点转换之后所在行的行号
int _col[10][10];//该点转换之后所在列的列号
vector<int> v[20];
int row_n, col_n;

int matching[20];
bool check[20];

bool dfs(int u){
	for (int i = 0; i < v[u].size(); i++){
		int pv = v[u][i];
		if(check[pv]) continue;
		check[pv] = true;
		if(matching[pv] == -1 || dfs(matching[pv])){
			matching[pv] = u;
			return true;
		}
	}
	return false;
}

int hangary(){
	int res = 0;
	memset(matching, -1, sizeof matching);
	for (int i = 1; i <= row_n; i++){
		memset(check, false, sizeof check);
		if(dfs(i)) res++;
	}
	return res;
}

int main()
{
	while(scanf("%d", &n), n){
		for (int i = 1; i <= n; i++){
			getchar();
			for (int j = 1; j <= n; j++){
				scanf("%c", &_grid[i][j]);
			}
		}
		//因为一行由于墙的原因可以容纳两个点同时存在，因此需要处理每个坐标的新的行号和列号
		memset(_row, 0, sizeof _row);
		memset(_col, 0, sizeof _col);
		row_n = 1, col_n = 1;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if(_grid[i][j] == '.' && _row[i][j] == 0){//处理横坐标
					for(int k = j; k <= n && _grid[i][k] == '.'; k++){
						_row[i][k] = row_n;
					}
					row_n++;
				}

				if(_grid[j][i] == '.' && _col[j][i] == 0){//处理纵坐标
					for (int k = j; k <= n && _grid[k][i] == '.'; k++){
						_col[k][i] = col_n;
					}
					col_n++;
				}
			}
		}

		//建二分图
		for (int i = 0; i <= 20; i++){
			v[i].clear();
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if(_grid[i][j] == '.'){
					v[_row[i][j]].push_back(_col[i][j]);
				}
			}
		}

		printf("%d\n", hangary());

	}
	return 0;
}

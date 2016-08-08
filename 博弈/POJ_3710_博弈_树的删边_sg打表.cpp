/**==================================
 | Author: YunHao
 | OJ: POJ
 | Kind: 博弈
 | Date: 
 | Describe:
 |          
 |          
 =================================**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

int grid[105][105];
int n, m, k;
int a, b;

int record[105];//记录当前节点访问的子节点是哪个
int tm[105];//记录时间戳，方便计算环上的边数
void dfs(int u, int dep, int fa){//处理图，将所有的偶数边的环删掉，奇数边的环变成一个边
    tm[u] = dep;

    for (int i = 1; i <= m; i++){
        if(grid[u][i] == 0) continue;
        if(i == fa) continue;//如果是访问的父节点，继续，防止误判环，因为存图的时候是双向边
        if(record[i] == 0){//节点没有访问过
            record[u] = i;
            dfs(i, dep+1, u);
        }
        else if(record[i] != 0){//节点访问过，出现环
            if((tm[u] - tm[i]) % 2 == 0){//环上有奇数边
                grid[u][fa] = 0;
                grid[fa][u] = 0;
                grid[i][record[i]] = 0;
                grid[record[i]][i] = 0;
            }
            else{
                grid[u][i] = 0;
                grid[i][u] = 0;
                grid[i][record[i]] = 0;
                grid[record[i]][i] = 0;
            }
        }
    }
    record[u] = 0;//节点没在当前dfs路径上
}

int sg[110];
bool visit[110];
int getsg(int u){//根节点的sg是0，中间节点的sg是子节点sg值+1后的抑或和
    visit[u] = true;
    int tmp = 0;
    for (int i = 1; i <= m; i++){
        if(grid[u][i] == 0) continue;
        if(visit[i]) continue;
        tmp ^= (getsg(i) + 1);
    }
    visit[u] = false;
    sg[u] = tmp;
    return tmp;
}

int main()
{
    while(~scanf("%d", &n)){
        int res = 0;
        for (int i = 0; i < n; i++){
            memset(grid, 0, sizeof grid);
            scanf("%d%d", &m, &k);
            for (int i = 0; i < k; i++){
                scanf("%d%d", &a, &b);
                if(grid[a][b]){
                    grid[a][b] = 0;
                    grid[b][a] = 0;
                }
                else{
                    grid[a][b] = 1;
                    grid[b][a] = 1;
                }
            }

            memset(record, 0, sizeof record);
            memset(tm, 0, sizeof tm);
            dfs(1, 1, 0);

            memset(sg, 0, sizeof sg);
            res ^= getsg(1);
        }
        if(res != 0)
            printf("Sally\n");
        else printf("Harry\n");
    }
    return 0;
}

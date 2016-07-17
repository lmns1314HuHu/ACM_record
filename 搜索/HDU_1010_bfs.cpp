#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n, m, t, total;
char grid[10][10];
bool visit[10][10];
bool flag;
int si, sj, ei, ej;


int dis[4][2] = {1,0,0,1,-1,0,0,-1};

bool inside(int i, int j){
    return i>=0 && i < n && j>=0 && j < m;
}

void dfs(int u, int v, int deep){
    if(grid[u][v] == 'X') return;
    else if(grid[u][v] == 'D'){
        if(deep == t)
            flag = true;
        return;
    }

    for (int i = 0; i < 4; i++){
        int unew = u + dis[i][0];
        int vnew = v + dis[i][1];

        if(inside(unew, vnew) && grid[unew][vnew] != 'X' && !visit[unew][vnew]){
            visit[unew][vnew] = true;
            dfs(unew, vnew, deep + 1);
            visit[unew][vnew] = false;
        }
        if(flag) return;
    }

}

int main()
{
    while(scanf("%d%d%d", &n, &m, &t)){
        if(n==0&&m==0&&t==0) break;
        for (int i = 0; i < n; i++){
            getchar();
            for (int j = 0; j < m; j++){
                scanf("%c", &grid[i][j]);
                if(grid[i][j] == 'S'){
                    si = i; sj = j;
                }
                else if(grid[i][j] == 'D'){
                    ei = i; ej = j;
                }
            }
        }

        getchar();//!!

        if((si+sj+ei+ej+t)%2==1 || (t < abs(si-ei)+abs(sj-ej))){
            printf("NO\n");
        }
        else{
            memset(visit, 0, sizeof visit);
            flag = false;
            visit[si][sj] = true;
            dfs(si, sj, 0);
            if(flag) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}

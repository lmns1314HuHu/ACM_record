#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char str[30];
char _cube[110][6];
//顶点编号从0开始的
#define MAXN 110
int uN,vN;//u,v数目
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];

bool dfs(int u)//从左边开始找增广路径
{
    for(int v=0; v<vN; v++){//这个顶点编号从0开始，若要从1开始需要修改
        if(g[u][v]&&!used[v]){
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v])){//找增广路，反向
                linker[v]=u;
                return true;
            }
        }
    }
    return false;//这个不要忘了，经常忘记这句
}

int hungary()
{
    int res=0, u;
    memset(linker, -1, sizeof(linker));
    for(u=0; u<uN; u++){
        memset(used, 0, sizeof(used));
        if(dfs(u))res++;
    }
    return res;
}

int main()
{
    while(~scanf("%s %d", str, &vN)){
        uN = strlen(str);
        for (int i = 0; i < vN; i++){
            for (int j = 0; j < 6; j++){
                getchar();
                scanf("%c", &_cube[i][j]);
                for (int k = 0; k < uN; k++){
                    if(str[k] == _cube[i][j]){
                        g[k][i] = 1;
                    }
                }
            }
        }
        if(hungary() == uN)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

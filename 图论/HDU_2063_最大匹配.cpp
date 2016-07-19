#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int k, m, n, a, b;
vector<int> V[550];
int matching[550];
bool check[550];

bool dfs(int u){
    int i, v;
    for (i = 0; i < V[u].size(); i++){
        v = V[u][i];
        if(check[v]) continue;
        check[v] = 1;
        if(matching[v] == -1 || dfs(matching[v])){
            matching[v] = u;
            return true;
        }
    }
    return false;
}

int hangary(int n_left){
    int i, ans = 0;
    memset(matching, -1, sizeof(matching));
    for (i = 1; i <= n_left; i++){
        memset(check, 0, sizeof(check));
        if(dfs(i)) ans++;
    }
    return ans;
}

int main()
{
    while(~scanf("%d", &k))
    {
        if(k == 0) break;
        scanf("%d%d", &m, &n);
        for (int i = 0; i <= m; i++)
        {
           V[i].clear();
        }
        for (int i = 0; i < k; i++)
        {
            scanf("%d%d", &a, &b);
            V[a].push_back(b);
        }
        printf("%d\n", hangary(m));
    }
    return 0;
}

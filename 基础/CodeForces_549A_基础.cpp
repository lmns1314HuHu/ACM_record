#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
char grid[55][55];

bool is(int u, int v){
    char str[5] = {'f','a','c','e'};
    for (int w = 0; w < 4; w++){
        bool flag = false;
        for (int i = u; i < u+2; i++){
            for (int j = v; j < v+2; j++){
                if(grid[i][j] == str[w]){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) return false;
    }
    return true;
}

int main()
{
    while(~scanf("%d%d", &n, &m)){

    for (int i = 0; i < n; i++){
        getchar();
        for (int j = 0; j < m; j++){
            scanf("%c", &grid[i][j]);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < m-1; j++){
            if(is(i, j))cnt++;
        }
    }
    printf("%d\n", cnt);
    }
//    for (int i = 0; i < n; i++){
//        for (int j = 0 ; j < m; j++){
//            cout << grid[i][j];
//        }
//        cout << endl;
//    }
    return 0;
}

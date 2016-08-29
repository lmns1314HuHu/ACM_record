/**==================================
 | Author: YunHao
 | OJ: 
 | Kind: 
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
#include <cmath>

using namespace std;
typedef long long ll;

int l, r, c;
int dis[][3] = {0,-1,0, 0,1,0, 0,0,-1, 0,0,1, 1,0,0, -1,0,0};
int sx, sy, sz, ex, ey, ez;
char grid[35][35][35];
int tm[35][35][35];

struct node{
    int x,y,z;
};

bool inside(int x, int y, int z){
    return x >= 0 && y >= 0 && z >= 0 && x < l && y < r && z < c;
}

int debfs(){
    memset(tm, 0, sizeof tm);
    node no;
    queue< node > qs, qe;
    no.x = sx; no.y = sy; no.z = sz;
    qs.push(no);
    no.x = ex; no.y = ey; no.z = ez;
    qe.push(no);
    tm[sx][sy][sz] = 1;
    tm[ex][ey][ez] = -1;

    while(!qs.empty() && !qe.empty()){
        node u = qs.front();
        qs.pop();
        for (int i = 0; i < 6; i++){
            int tmpx = u.x+dis[i][0];
            int tmpy = u.y+dis[i][1];
            int tmpz = u.z+dis[i][2];
            if(inside(tmpx, tmpy, tmpz) && grid[tmpx][tmpy][tmpz] == '.'){
                if(tm[tmpx][tmpy][tmpz] > 0) continue;
                if(tm[tmpx][tmpy][tmpz] != 0)
                    return abs(tm[tmpx][tmpy][tmpz] - tm[u.x][u.y][u.z])-1;
                else
                    tm[tmpx][tmpy][tmpz] = tm[u.x][u.y][u.z]+1;
                node tmpno;
                tmpno.x = tmpx;
                tmpno.y = tmpy;
                tmpno.z = tmpz;
                qs.push(tmpno);
            }
        }

        node v = qe.front();
        qe.pop();
        for (int i = 0; i < 6; i++){
            int tmpx = v.x+dis[i][0];
            int tmpy = v.y+dis[i][1];
            int tmpz = v.z+dis[i][2];
            if(inside(tmpx, tmpy, tmpz) && grid[tmpx][tmpy][tmpz] == '.'){
                if(tm[tmpx][tmpy][tmpz] < 0) continue;
                if(tm[tmpx][tmpy][tmpz] != 0)
                    return abs(tm[tmpx][tmpy][tmpz] - tm[v.x][v.y][v.z])-1;
                else
                    tm[tmpx][tmpy][tmpz] = tm[v.x][v.y][v.z]-1;
                node tmpno;
                tmpno.x = tmpx;
                tmpno.y = tmpy;
                tmpno.z = tmpz;
                qe.push(tmpno);
            }
        }
    }
    return -1;
}

int main()
{
    while(~scanf("%d%d%d", &l, &r, &c)){
        if(l == 0 && r == 0 && c == 0) break;
        for (int i = 0; i < l; i++){
            for (int j = 0; j < r; j++)
                scanf("%s", grid[i][j]);
        }
        for (int i = 0; i < l; i++){
            for (int j = 0; j < r; j++){
                for (int k = 0; k < c; k++){
                    if(grid[i][j][k] == 'S'){
                        sx = i;
                        sy = j;
                        sz = k;
                    }
                    else if(grid[i][j][k] == 'E'){
                        ex = i;
                        ey = j;
                        ez = k;
                    }
                }
            }
        }
        int ans = debfs();
        if(ans != -1)
            printf("Escaped in %d minute(s).\n", ans);
        else
            printf("Trapped!\n");
    }
    return 0;
}

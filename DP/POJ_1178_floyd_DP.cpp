/**==================================
 | Author: YunHao
 | OJ: POJ
 | Kind: Floyd DP
 | Date: 2016/8/3
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
#define inf 900000000
int king_move[][2] = {-1,0, -1,-1, 0,-1, 1,1, 0,1, 1,0, 1,-1, -1,1};
int knight_move[][2] = {-2,1, 2,1, 1,2, 1,-2, -1,-2, -2,-1, -1,2, 2,-1,};

int king_map[64][64];
int knight_map[64][64];
char str[200];
vector<int> kn;
int kx, ky;

bool inside(int x, int y){
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

void decode(int cd, int& x, int& y){
    x = cd / 8;
    y = cd % 8;
}

int code(int x, int y){
    return x*8+y;
}

void build_map(){//建图
    for (int i = 0; i < 64; i++){
        for (int j = 0; j < 64; j++){
            king_map[i][j] = inf;
            knight_map[i][j] = inf;
        }

        king_map[i][i] = 0;
        knight_map[i][i] = 0;

        int curx, cury, nxtx, nxty;
        decode(i, curx, cury);

        for (int j = 0; j < 8; j++){
            nxtx = curx + king_move[j][0];
            nxty = cury + king_move[j][1];
            if(inside(nxtx, nxty)){
                int nxt = code(nxtx, nxty);
                king_map[i][nxt] = 1;
            }

            nxtx = curx + knight_move[j][0];
            nxty = cury + knight_move[j][1];
            if(inside(nxtx, nxty)){
                int nxt = code(nxtx, nxty);
                knight_map[i][nxt] = 1;
            }
        }
    }
}

void floyd(){
    for (int k = 0; k < 64; k++){
        for (int i = 0; i < 64; i++){
            for (int j = 0; j < 64; j++){
                if(king_map[i][k] + king_map[k][j] < king_map[i][j])
                    king_map[i][j] = king_map[i][k] + king_map[k][j];
                if(knight_map[i][k] + knight_map[k][j] < knight_map[i][j])
                    knight_map[i][j]  = knight_map[i][k] + knight_map[k][j];
            }
        }
    }
}

int main()
{
    build_map();
    floyd();
    while(~scanf("%s", str)){
        int len = strlen(str);
        int kx = str[0]-'A';
        int ky = str[1]-'1';
        int kpos = code(kx, ky);
        for (int i = 2; i < len - 1; i+=2){
            int knx = str[i] - 'A';
            int kny = str[i+1] - '1';
            int knpos = code(knx, kny);
            kn.push_back(knpos);
        }
        int dis = 100000000;
        for (int i = 0; i < 64; i++){//枚举64个汇合位置
            int total_knight = 0;
            for (int k = 0; k < kn.size(); k++)
                total_knight += (knight_map[i][kn[k]]);
            for (int j = 0; j < 64; j++){//枚举64个接国王的位置
                int tmp_knight;
                for (int k = 0; k < kn.size(); k++){//枚举每个骑士接国王
                    tmp_knight = total_knight - knight_map[i][kn[k]];
                    tmp_knight += king_map[kpos][j];
                    tmp_knight += knight_map[kn[k]][j];
                    tmp_knight += knight_map[j][i];
                    if(tmp_knight < dis)//求最短的距离
                        dis = tmp_knight;
                }
            }
        }
        if(dis == 100000000)//特判一下如果只有国王一个棋子
            printf("0\n");
        else printf("%d\n", dis);
    }
    return 0;
}

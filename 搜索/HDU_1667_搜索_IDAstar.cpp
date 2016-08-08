#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

int grid[10][10];
int cnt[4];
char stk[1010];
bool flag;

struct node{
    int f, g, h;
};

int f(node& no){//评估函数，数值为8-最多的相同块数
    memset(cnt, 0, sizeof cnt);
    for(int i = 3; i <= 5; i++)
        cnt[grid[3][i]]++;
    cnt[grid[4][3]]++;
    cnt[grid[4][5]]++;
    for(int i = 3; i <= 5; i++)
        cnt[grid[5][i]]++;
    no.h = 8-max(max(cnt[1], cnt[2]), cnt[3]);
    no.f = no.g + no.h;
    return no.f;
}

void up(int col){
    for (int i = 0; i <= 6; i++)
        grid[i][col] = grid[i+1][col];
    grid[7][col] = grid[0][col];
}

void down(int col){
    for (int i = 8; i > 1; i--)
        grid[i][col] = grid[i-1][col];
    grid[1][col] = grid[8][col];
}

void lef(int row){
    for (int i = 0; i <= 6; i++)
        grid[row][i] = grid[row][i+1];
    grid[row][7] = grid[row][0];
}

void rig(int row){
    for (int i = 8; i > 1; i--)
        grid[row][i] = grid[row][i-1];
    grid[row][1] = grid[row][8];
}

void oper(int tp){
    if(tp == 1) up(3);
    else if(tp == 2) up(5);
    else if(tp == 3) rig(3);
    else if(tp == 4) rig(5);
    else if(tp == 5) down(5);
    else if(tp == 6) down(3);
    else if(tp == 7) lef(5);
    else if(tp == 8) lef(3);
}

void unoper(int tp){
    if(tp == 1) down(3);
    else if(tp == 2) down(5);
    else if(tp == 3) lef(3);
    else if(tp == 4) lef(5);
    else if(tp == 5) up(5);
    else if(tp == 6) up(3);
    else if(tp == 7) rig(5);
    else if(tp == 8) rig(3);
}

int mx;
void ida_star(node no, int dep, int preoper){//上一个节点，已经操作的次数，上一次操作类型
    if(mx-dep < no.h)//剪枝1，如果剩余深度小于当前的评估函数值，则肯定不能到达，剪掉
        return;

    if(dep == mx && no.h == 0){//在最大深度，如果当前评估函数值是0，则找到，直接返回
        flag = true;
        return;
    }

    if(dep >= mx){//如果已经操作的深度大于最大深度，返回
        return;
    }

    node v;
    for(int i = 1; i <= 8; i++){

        if(i == 1 && preoper == 6)continue;//剪枝2，如果此次操作与上一次是反操作，减掉
        if(i == 6 && preoper == 1)continue;
        if(i == 2 && preoper == 5)continue;
        if(i == 5 && preoper == 2)continue;
        if(i == 3 && preoper == 8)continue;
        if(i == 8 && preoper == 3)continue;
        if(i == 4 && preoper == 7)continue;
        if(i == 7 && preoper == 4)continue;

        oper(i);
        stk[dep] = ('A' - 1 + i);
        v.g = dep;
        f(v);
        if(mx-dep-1 >= v.h){//！不能过多剪枝，如果剪错（比如加上 v.f<=no.f 的条件），就会错过本来在浅层的解，使迭代加深陷入更深的搜索树
            ida_star(v, dep + 1, i);
        }
        if(flag) break;//如果找到解，直接返回
        unoper(i);
    }
}

int main()
{
    node root;
    while(scanf("%d", &grid[1][3]), grid[1][3]){
        scanf("%d%d%d", &grid[1][5], &grid[2][3], &grid[2][5]);
        for (int i = 1; i <= 7; i++)
            scanf("%d", &grid[3][i]);
        scanf("%d%d", &grid[4][3], &grid[4][5]);
        for (int i = 1; i <= 7; i++)
            scanf("%d", &grid[5][i]);
        scanf("%d%d%d%d", &grid[6][3], &grid[6][5], &grid[7][3], &grid[7][5]);

        flag = false;
        root.g = 0;
        f(root);
        mx = root.h;//下界是当前状态的评估函数值。省去一些些无用的搜索。
        if(root.h == 0){
            printf("No moves needed\n");
            printf("%d\n", grid[3][3]);
            continue;
        }
        while(1){
            ida_star(root, 0, -1);
            if(flag) break;
            mx++;
        }
        for (int i = 0; i < mx; i++)
            printf("%c", stk[i]);
        for (int i = 1; i <= 3; i++){
            if(cnt[i] != 0){
                printf("\n%d\n", i);
                break;
            }
        }
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

int y;
char grid[10];
int mx;
bool flag;
bool visit[370000];
int fac[10];

void calc_fac(){//计算阶乘
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= 8; i++)
        fac[i] = fac[i-1]*i;
}

int cantor(){//康拓展开
    int sum = 0;
    int fac_num = 8;
    for (int i = 1; i <= 9; i++){
        int cnt = 0;
        for (int j = i + 1; j <= 9; j++){
            if(grid[j] < grid[i]) cnt++;
        }
        sum += cnt*fac[fac_num--];
    }
    return sum;
}

void oper1(int num){//顺时针旋转操作
    int tmp = grid[num];
    grid[num] = grid[num + 3];
    grid[num + 3] = grid[num + 4];
    grid[num + 4] = grid[num + 1];
    grid[num + 1] = tmp;
}

void oper2(int num){//逆时针旋转操作
    int tmp = grid[num];
    grid[num] = grid[num + 1];
    grid[num + 1] = grid[num + 4];
    grid[num + 4] = grid[num + 3];
    grid[num + 3] = tmp;
}

void oper(int num){//8种操作
    if(num == 1) oper1(1);
    else if(num == 2) oper1(2);
    else if(num == 3) oper1(4);
    else if(num == 4) oper1(5);
    else if(num == 5) oper2(1);
    else if(num == 6) oper2(2);
    else if(num == 7) oper2(4);
    else if(num == 8) oper2(5);
}

void unoper(int num){//8种反操作
    if(num == 1) oper2(1);
    else if(num == 2) oper2(2);
    else if(num == 3) oper2(4);
    else if(num == 4) oper2(5);
    else if(num == 5) oper1(1);
    else if(num == 6) oper1(2);
    else if(num == 7) oper1(4);
    else if(num == 8) oper1(5);
}

void iddfs(int dep, int fctr){
    if(fctr == 0){//如果康拓展开值是0，即是有序了。找到解
        flag = true;
        return;
    }
    if(dep >= mx) return;//大于最大深度返回

    for (int i = 1; i <= 8; i++){
        oper(i);
        int ctr = cantor();
        if(!visit[ctr]){//当前状态没有出现过
            visit[ctr] = true;//
            iddfs(dep + 1, ctr);
            visit[ctr] = false;//找到结果返回前，清空visit数组，不用每次都初始化
            if(flag) return;
        }
        unoper(i);
    }
}

int main()
{
    calc_fac();
    int w = 1;
    while(~scanf("%c", &grid[0])){
        for (int i = 1; i <= 9; i++)
            scanf("%c", &grid[i]);
        if(grid[1] == '0') break;
        getchar();
        y = grid[0]-'0';
        
        mx = 0;
        flag = false;
        int root_ctr = cantor();

        visit[root_ctr] = true;//visit数组这样写不用每组case都初始化
        for ( ; mx <= y; mx++){
            iddfs(0, root_ctr);
            if(flag) break;
        }
        visit[root_ctr] = false;//visit数组这样写不用每组case都初始化

        if(!flag)
            printf("%d. -1\n", w++);
        else printf("%d. %d\n", w++, mx);

    }
    return 0;
}

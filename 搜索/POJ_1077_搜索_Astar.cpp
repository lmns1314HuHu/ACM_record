#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

struct node{
    int f, sheng, dep;//分别存估值函数，当前步数，剩余曼哈顿距离
    char s[10];//当前状态
    int xi, xj;
    vector<char> v;//当前路径
    bool operator < (const node& no2)const{
        return this->f > no2.f;
    }
};

bool visit[400000];
int dis[][2] = {1,0,-1,0,0,1,0,-1};
char fang[4] = {'d', 'u', 'r', 'l'};
priority_queue<node> q;
char ss[10];

int fac[10]={};
void calc_fac(){//计算阶乘
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= 8; i++)
        fac[i] = i*fac[i-1];
}

int cantor(node& no){//康拓展开
    int sum = 0;
    int fac_num = 8;
    for (int i = 0; i < 9; i++){
        int cnt = 0;
        for (int j = i+1; j < 9; j++){
            if(no.s[j] < no.s[i]) cnt++;
        }
        sum += cnt*fac[fac_num--];
    }
    return sum;
}

void calc_f(node& no){//估值函数
    no.f = 0;
    no.sheng = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(no.s[3*i+j] == 'x' || no.s[3*i+j] == '9'){
                no.xi = i;
                no.xj = j;
                no.s[3*i+j]='9';
            }
            int x = (no.s[3*i+j]-'0'-1) / 3;
            int y = (no.s[3*i+j]-'0'-1) % 3;
            no.f += (fabs(i-x)+fabs(j-y));
        }
    }
    no.sheng = no.f;
    no.f += no.dep;
}

bool inside(int a, int b){
    return a >= 0 && b >= 0 && a < 3 && b < 3;
}

bool bfs(char* s){
    memset(visit, 0, sizeof visit);
    while(q.size())q.pop();
    node root, u, no;//不要在while循环中创建，因为会消耗更多的时间
    int k = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            root.s[3*i+j] = s[k++];
        }
    }
    root.dep = 0;
    calc_f(root);
    visit[cantor(root)] = true;
    root.v.clear();
    q.push(root);

    while(!q.empty()){
        u = q.top();
        q.pop();
        int xi = u.xi, yi = u.xj;
        int dep = u.dep;

        for (int i = 0; i < 4; i++){
            int xnew = xi+dis[i][0], ynew = yi+dis[i][1];

            if(inside(xnew, ynew)){
                strcpy(no.s, u.s);
                swap(no.s[3*xi+yi], no.s[3*xnew+ynew]);

                int cantor_ = cantor(no);
                if(visit[cantor_]) continue;//访问过就不要放入队列了

                no.dep = dep + 1;

                calc_f(no);
                visit[cantor_] = true;
                no.v.assign(u.v.begin(), u.v.end());
                no.v.push_back(fang[i]);

                if(no.sheng == 0){
                    for (int i = 0; i < no.v.size(); i++){
                        printf("%c", no.v[i]);
                    }
                    printf("\n");
                    return true;
                }
                q.push(no);
            }
        }
    }
    return false;
}

int main()
{
    calc_fac();
    while(~scanf("%c", &ss[0])){
        for (int i = 1; i < 9; i++){
            getchar();
            scanf("%c", &ss[i]);
        }
        getchar();
        ss[9] = '\0';
        if(!bfs(ss)){
            printf("unsolvable\n");
        }
    }
    return 0;
}

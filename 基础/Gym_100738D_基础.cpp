#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int num[200010];
int tmp;
struct node{
    int num, v;
}no[200010];

queue< pair<int, int> >q;
int chu[200010];

bool cmp(node no1, node no2){
    return no1.num > no2.num;
}

int main()
{
    while(~scanf("%d", &n)){
        while(q.size())q.pop();
        memset(chu, 0, sizeof chu);
        bool flag = true;
        for (int i = 1; i <= n; i++){
//            scanf("%d", &num[i]);
            scanf("%d", &tmp);
            no[i].num = tmp;
            no[i].v = i;

            if(no[i].num <= 0)
                flag = false;
        }

        sort(no+1, no+n+1, cmp);

        if(flag){

        for (int i = 1; i <= n; i++){
            if(q.empty()){
                if(i == n){
                    flag = false;
                    break;
                }
                if(i+1 < n && no[i].num > 0 && no[i+1].num > 0){
                    if(i != 1 && chu[no[i].v] == 0){
                        flag = false;
                        break;
                    }
                    chu[no[i+1].v] = no[i].v;
                    no[i].num--;
                    no[i+1].num--;
//                    num[i]--; num[i+1]--;
                }
                if(no[i].num > 0){
                    q.push(make_pair(no[i].v, i));
                }
            }
            else{
                int fu = q.front().second;
                if(no[fu].num > 0 && no[i].num > 0){
                    if(chu[no[i].v] == 0){
                        no[i].num--;
                        no[fu].num--;
                        //num[i]--;
//                        num[fu]--;
                        chu[no[i].v] = no[fu].v;
                    }
                }
                if(no[fu].num <= 0)
                    q.pop();
                if(no[i].num > 0)
                    q.push(make_pair(no[i].v, i));
            }
        }

        }
        if(q.size()) flag = false;
        if(n == 1 && no[1].num == 0){
            flag = true;
        }
        if(!flag) printf("-1\n");
        else {
            for (int i = 1; i <= n; i++){
                if(i == no[1].v) continue;
                printf("%d %d\n", chu[i], i);
            }
        }
    }
    return 0;
}

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

#define maxn 100010

int m;
int sum[maxn*4];

void build(){
    memset(sum, 0, sizeof sum);
}

void maintain(int o){
    int lc=o<<1, rc=o<<1|1;
    sum[o] = sum[lc] + sum[rc];
}

bool update(int o, int l, int r, int pos, int val){//正常的更新函数
    if(l == r){
        if(sum[o] == 0 && val < 0) return false;
        sum[o] += val;
        return true;
    }
    int mid=(l+r)>>1, lc=o<<1, rc=o<<1|1;
    bool res = false;
    if(pos <= mid) res = update(lc, l, mid, pos, val);
    else res = update(rc, mid+1, r, pos, val);
    maintain(o);
    return res;
}

int ret;//存储大于等于pos的第k个数是几
void query(int o, int l, int r, int pos, int& rk){//查询pos（包含）之后的第k个数是多少。题目要求是求比pos大的第k个数，见第85行
    if(rk <= 0 || sum[o] == 0) return;//要查的rk值是0或者此区间内没有数
    if(l == r){//每次到根节点就更新ret值
        ret = l;
        rk -= sum[o];
        return;
    }
    if(pos <= l && rk > sum[o]){//如果该区间在pos后并且该区间的数之和小于rk，那么rk直接减去，因为要查的值一定不在该区间。
        rk -= sum[o];
        return;
    }
    int mid = (l+r)>>1, lc=o<<1, rc=o<<1|1;
    if(pos <= mid) query(lc, l, mid, pos, rk);//如果pos在左区间，那么要查左区间
    query(rc, mid+1, r, pos, rk);//否则直接查找右区间
}

int main()
{
    while(~scanf("%d", &m)){
        build();
        for (int i = 0; i < m; i++){
            int op1, op2, op3;
            scanf("%d%d", &op1, &op2);
            if(op1 == 0){
                update(1, 1, 100000, op2, 1);
            }
            else if(op1 == 1){
                if(update(1, 1, 100000, op2, -1) == false){
                    printf("No Elment!\n");
                }
            }
            else if(op1 == 2){
                scanf("%d", &op3);
                ret = 0;
                query(1, 1, 100000, op2+1, op3);//本行在传递的时候已经处理了比pos大的第k个数，即求大于等于op2+1的第k个数
                if(ret == 0 || op3 > 0) printf("Not Find!\n");//因为每次到叶节点就更新，如果op3的值最后小于等于0了，说名找到了，如果没有的话，说明此时找的这个ret不是结果，没找到。
                else printf("%d\n", ret);
            }
        }
    }
    return 0;
}

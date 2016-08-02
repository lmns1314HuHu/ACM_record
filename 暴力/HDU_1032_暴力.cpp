/**==================================
 | Author: YunHao
 | OJ: HDU
 | Kind: 暴力
 | Date: 2016/8/1
 | Describe:记忆化搜索会报RE，目测是爆栈
 |          
 |          
 =================================**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int dp[3000010];
int x, y;
queue<int> q;

int main()
{
    while(~scanf("%d%d", &x, &y)){
        int begi = min(x, y);
        int ed = max(x, y);
        int res = 0;
        for (int i = begi; i <= ed; i++){
            int cnt = 1;
            int num = i;
            while(num != 1){
                if(num % 2 == 0)
                    num /= 2;
                else num = num * 3 + 1;
                cnt++;
            }
            if(cnt > res)
                res = cnt;

            //if(dp[i] != 0){
                //if(dp[i] > res)
                    //res = dp[i];
            //}
            //else{
                //int cnt = 1;
                //int num = i;
                //q.push(i);
                //while(num != 1){
                    //if(dp[num] != 0){
                        //cnt += (dp[num] - 1);
                        //break;
                    //}
                    //if(num % 2 == 0)
                        //num /= 2;
                    //else
                        //num = num * 3 + 1;
                    //q.push(num);
                    //cnt++;
                //}
                //while(!q.empty()){
                    //int u = q.front();
                    //q.pop();
                    //dp[u] = cnt--;
                //}
                //if(dp[i] > res)
                    //res = dp[i];
            //}

        }
        printf("%d %d %d\n",x, y, res);
    }
    return 0;
}

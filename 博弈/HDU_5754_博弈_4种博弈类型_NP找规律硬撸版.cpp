#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int t, type, n, m;
int _grid[1010][1010];

bool inside(int a, int b){
    return a >= 1 && b >= 1 && a <= n && b <= m;
}

struct node{
    int a, b, k;
};

queue<node> q;
int dis[][2] = {2, 1, 1, 2};

bool visit_for_queen[1010];
pair<int, int> q2[1010];

int main()
{
    //打印皇后棋子的先手必败的点
    memset(visit_for_queen, 0, sizeof visit_for_queen);
    bool flag = false;
    int k = 0;
    for (int i = 0; 1 ;i++){
        int rem_qian = -1;
        for (int j = 1; j <= 1000; j++){
            if(!visit_for_queen[j] && rem_qian == -1){
                rem_qian = j;
            }
        }
        if(rem_qian == -1) break;
        q2[k].first = rem_qian, q2[k++].second = rem_qian+i;
        visit_for_queen[rem_qian] = true;
        if(rem_qian+i <= 1000)
            visit_for_queen[rem_qian+i] = true;
    }

    //memset(_grid, -1, sizeof _grid);
    //_grid[1][1] = 0;
    //_grid[3][2] = _grid[2][3] = 1;
    //node no;
    //no.a = 3, no.b = 2, no.k = 1;
    //q.push(no);
    //no.b = 3, no.a = 2;
    //q.push(no);
    //while(!q.empty()){
        //node u = q.front();
        //q.pop();
        //for (int i = 0; i < 2; i++){
            //int x = u.a+dis[i][0], y = u.b+dis[i][1];
            //if(inside(x, y)){
                //node v;
                //v.a = x, v.b = y;
                //v.k = u.k+1;
                //if(_grid[x][y] == -1){
                    //q.push(v);
                    //_grid[x][y] = v.k;
                //}
            //}
        //}
    //}

    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &type, &n, &m);
        if(type == 1){
            if(m % 2 == 1 && n % 2 ==1){
                printf("G\n");
            }
            else {
                printf("B\n");
            }
        }
        else if(type == 2){
            if(n != m){
                printf("B\n");
            }
            else 
                printf("G\n");
        }
        else if(type == 3){
            //write by sfm
            for(int i=n;i>=1;i--){
				for(int j=m;j>=1;j--){
					if(i==n&&j==m){
						_grid[i][j] = 0;
						continue;
					}
					int sx1 = i + dis[0][0];
					int sy1 = j + dis[0][1];
					int sx2 = i + dis[1][0];
					int sy2 = j + dis[1][1];
					int cntD = 0,cntL = 0,cntW = 0;
					if(!inside(sx1,sy1)){
						cntD++;
					}else{
						if(_grid[sx1][sy1] == 1){
							cntW++;
						}
						if(_grid[sx1][sy1] == 0){
							cntL++;
						}
						if(_grid[sx1][sy1] == -1){
							cntD++;
						}
					}
					if(!inside(sx2,sy2)){
						cntD++;
					}else{
						if(_grid[sx2][sy2] == 1){
							cntW++;
						}
						if(_grid[sx2][sy2] == 0){
							cntL++;
						}
						if(_grid[sx2][sy2] == -1){
							cntD++;
						}			
					}
					if(cntD==2){
						_grid[i][j] = -1;
					}else if(cntD==1){
						if(cntW){
							_grid[i][j] = -1;
						}else{
							_grid[i][j] = 1;
						}
					}else{
						if(cntL){
							_grid[i][j] = 1; 
						}else{
							_grid[i][j] = 0;
						}
					}
				}
			
			}

            if(_grid[1][1] == 0){
                printf("G\n");
            }
            else if(_grid[1][1] == 1) {
                printf("B\n");
            }
            else{
                printf("D\n");
            }
        }
        else if(type == 4){
            bool sig = false;
            if(n > m) swap(n, m);
            for (int i = 0; i < k; i++){
                if(q2[i].first == n && q2[i].second == m){
                    sig = true;
                    break;
                }
            }
            if(sig){
                printf("G\n");
            }
            else
                printf("B\n");
        }
    }
    return 0;
}

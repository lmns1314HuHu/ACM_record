#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
#define maxn 35
int dp[maxn*3];
int x, y, z;

struct block{
    int l, w, h;
}box[maxn*3];

bool cmp(block b1, block b2){
    if(b1.l > b2.l){
        return true;
    }
    else if(b1.l < b2.l){
        return false;
    }
    else{
        return b1.w > b2.w;
    }
}

//longest increasing sequence
//n2
int main()
{
    int t = 1;
    while(scanf("%d", &n), n){
        int k = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++){
            scanf("%d%d%d", &x, &y, &z);

            if(x > y){
                box[k].l = x, box[k].w = y, box[k].h = z;
            }
            else{
                box[k].l = y, box[k].w = x, box[k].h = z;
            }
            k++;

            if(y > z){
                box[k].l = y, box[k].w = z, box[k].h = x;
            }
            else{
                box[k].l = z, box[k].w = y, box[k].h = x;
            }
            k++;

            if(z > x){
                box[k].l = z, box[k].w = x, box[k].h = y;
            }
            else{
                box[k].l = x, box[k].w = z, box[k].h = y;
            }
            k++;
        }

        sort(box, box + k, cmp);

//        for (int i = 0; i < k; i++){
//            cout << box[i].l << " " << box[i].w << " " << box[i].h <<endl;
//        }

        int res = 0;
        for (int i = 0; i < k; i++){
            dp[i] = box[i].h;
            for (int j = 0; j < i; j++){
                if(box[i].w < box[j].w && box[i].l < box[j].l){
                    dp[i] = max(dp[i], dp[j] + box[i].h);
                }
            }
            res = max(res, dp[i]);
        }

        printf("Case %d: maximum height = %d\n", t++, res);
    }

    return 0;
}

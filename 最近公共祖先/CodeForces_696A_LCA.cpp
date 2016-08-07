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
#include<map>
using namespace std;
typedef long long ll;

int q, ev;
ll v, u, w;
map<ll, int> ms;
ll dis[200010];
ll ceng[65];

ll calc_deep(ll num){
    int i;
    for (i = 1; i < 64; i++){
        if(num < ceng[i]){
            return i;
        }
    }
    return i;
}

int main()
{
    scanf("%d", &q);
    ceng[1] = 2;
    for (int i = 2; i < 64; i++){
        ceng[i] = ceng[i-1]*2;
    }
    int cnt = 1;
    for (int i = 0; i < q; i++){
        scanf("%d%lld%lld", &ev, &v, &u);
        if(ev == 1){
            scanf("%lld", &w);
            if(v > u) swap(v, u);

            int cengv = calc_deep(v);
            int cengu = calc_deep(u);

            int cnt1 = cengu - cengv;
            while(cnt1--){
                if(ms[u] == 0){
                    ms[u] = cnt++;
                }
                dis[ms[u]] += w;
                u /= 2;
            }

            while(v != u){
                if(ms[v] == 0){
                    ms[v] = cnt++;
                }
                dis[ms[v]] += w;
                if(ms[u] == 0){
                    ms[u] = cnt++;
                }
                dis[ms[u]] += w;
                v /= 2;
                u /= 2;
            }
        }
        else{
            if(v > u) swap(v, u);
            ll res = 0;

            int cengv = calc_deep(v);
            int cengu = calc_deep(u);

            int cnt1 = cengu - cengv;
            while(cnt1--){
                res += dis[ms[u]];
                u /= 2;
            }

            while(u != v){
                res += dis[ms[u]];
                res += dis[ms[v]];
                u /= 2;
                v /= 2;
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}

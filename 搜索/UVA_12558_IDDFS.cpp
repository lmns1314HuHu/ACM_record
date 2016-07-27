#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define hehe int main(){
#define endhehe return 0;}
#define maxn 100100

typedef long long ll;
ll num[maxn];//记录最后输出的数
ll st[maxn];//dfs中的压栈
bool nouse[1010];//记录不能使用的数
int t, a, b, k, k2;
bool flag;

ll gcd(ll a, ll b){
	while(b != 0){
		ll tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}

struct node{
	ll a, b;
};

ll mx;//当前dfs的最大深度
void dfs(node no, node less_than, ll dep){
    st[dep] = less_than.b;

	if (no.a == 1 && no.b > less_than.b && dep == mx){
	    if(no.b > 1000 || (no.b <= 1000 && !nouse[no.b])){
            flag = true;//在当前深度找到了解
            st[dep+1] = no.b;
            bool chang = true;
            for (int i = dep+1; i >= 2; i--){ // 判断是否应该更新num数组
                if(num[i] == -1){
                    chang = true;
                    break;
                }
                else if(num[i] == st[i])
                    continue;
                else if(num[i] > st[i]){
                    chang = true;
                    break;
                }
                else if(num[i] < st[i]){
                    chang = false;
                    break;
                }
            }
            if(chang){
                for (int i = 2; i <= dep+1; i++)
                    num[i] = st[i];
            }
            return ;
        }
	}

	if(dep >= mx) return;

	ll step = mx - dep + 1;
	node xin, v;
	xin.a = 1, xin.b = max(less_than.b + 1, no.b / no.a);//下界,控制不好会TLE
	int shangjie = step * no.b / no.a;//上届,控制不好会TLE
	for ( ; xin.b <= shangjie; xin.b++){
	    if(xin.b <= 1000 && nouse[xin.b]) continue;

	    ll _gcd = gcd(no.b, xin.b);
	    ll _lcm = no.b / _gcd * xin.b;
		v.b = _lcm;
		v.a = (_lcm / no.b * no.a - _lcm / xin.b * xin.a);

		if(v.a > 0){
		    ll _gcd = gcd(v.a, v.b);
		    v.a /= _gcd;
		    v.b /= _gcd;
		    dfs(v, xin, dep+1);
		}
	}
}

hehe
	scanf("%d", &t);
	for (int w = 1; w <= t; w++){
	    scanf("%d%d%d", &a, &b, &k);
	    k2 = 1;
	    memset(nouse, 0, sizeof nouse);
	    for (int i = 0; i < k; i++){
	        int no;
	        scanf("%d",  &no);
	        nouse[no] = true;
	    }

	    flag = false;
	    node no1, no2;
	    no1.a = a, no1.b = b;
	    no2.a = 1, no2.b = 1;
	    memset(num, -1, sizeof num);

	    mx = 1;
	    while(!flag){
	        dfs(no1, no2, 1);
	        mx++;
	    }

	    printf("Case %d: %d/%d=", w, a, b);
	    for (int i = 2; i < mx+1; i++){
	        printf("1/%lld", num[i]);
	        if(i != mx)
	            printf("+");
	        else printf("\n");
	    }
	}
endhehe

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

int n, k;
int num[100010];
int cap;
bool visit[100010];
ll total, totalshoudu;

int main()
{
	while(~scanf("%d%d", &n, &k)){
		memset(visit, 0, sizeof visit);
		total = 0, totalshoudu = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &num[i]);
			total += num[i];
		}
		for (int i = 0; i < k; i++){
			scanf("%d", &cap);
			totalshoudu += num[cap-1];
			visit[cap-1] = true;
		}
		ll res = 0;
		for (int i = 0; i < n; i++){
			if(visit[i]){
				res += num[i] * total;
				res -= num[i] * num[i];
			}
			else{
				if(!visit[(i + 1) % n])
					res += num[i] * num[(i+1)%n];
				if(!visit[(i - 1 + n) % n])
					res += num[i] * num[(i-1+n)%n];
				res += num[i]*totalshoudu;
			}
		}
		printf("%I64d\n", res / 2);
	}
	return 0;
}

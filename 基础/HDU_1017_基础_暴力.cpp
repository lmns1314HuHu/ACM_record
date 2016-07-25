#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, t;

int main()
{
	scanf("%d", &t);
	for(int y = 0; y < t; y++){
		int w = 1;
		while(~scanf("%d%d", &n, &m)){
			if(n==0&&m==0) break;
			int res = 0;
			for (int i = 1; i < n; i++){
				for (int j = i+1; j < n; j++){
					if((i*i+j*j+m)%(i*j) == 0)
						res++;
				}
			}
			printf("Case %d: %d\n", w++, res);
		}
		if(y != t-1)
			printf("\n");
	}
	return 0;
}
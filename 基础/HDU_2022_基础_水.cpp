#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int m, n;
int num;

int main()
{
	while(~scanf("%d%d", &n, &m)){
		int mx = -1;
		int shiji = 0;
		int x = -1, y = -1;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				scanf("%d", &num);
				int tmp = abs(num);
				if(tmp > mx){
					mx = tmp;
					shiji = num;
					x = i;
					y = j;
				}
			}
		}
		printf("%d %d %d\n", x+1, y+1, shiji);
	}
	return 0;
}
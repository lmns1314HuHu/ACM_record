#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, m, num;
	while(~scanf("%d%d", &n, &m)){
		if(n==0&&m==0) break;
		bool flag = false;
		bool _finish = false;
		for (int i = 0; i < n; i++){
			scanf("%d", &num);
			if(num < m){
				if(flag) printf(" ");
				printf("%d", num);
				flag = true;
			}
			else{
				if(!_finish){
					if(flag) printf(" ");
					printf("%d", m);
					_finish = true;
					flag = true;
				}
				if(flag) printf(" ");
				printf("%d", num);
				flag = true;
			}
		}
		 printf("\n");
	}
	return 0;
}
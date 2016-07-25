#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a, b, n;
int num[100];

int main()
{
	while(~scanf("%d%d%d", &a, &b, &n)){
		if(a==0&&b==0&&n==0) break;
		int _begin = -1, _end = -1;
		num[0] = 1;
		num[1] = 1;
		num[2] = 1;
		bool flag = false;
		for (int i = 3; i <= n; i++){
			num[i] = ( a*num[i-1]+b*num[i-2] ) % 7;
			for ( int j = 2; j < i-2; j++ ){
				if( num[j]==num[i] && num[j-1]==num[i-1] ){
					flag = true;
					_begin = j-1;
					_end = i-2;
					break;
				}
			}
			if(flag)
				break;
		}
		if(!flag)
			printf("%d\n", num[n]);
		else{
			printf("%d\n", num[(n-_begin+1-1)%(_end-_begin+1)+1+_begin-1]);
		}
	}
	return 0;
}
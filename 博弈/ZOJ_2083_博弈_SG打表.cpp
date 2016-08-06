#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int sg[55];
bool visit[55];

void getsg(){
	memset(sg, 0, sizeof sg);
	sg[0] = 0;
	for (int i = 2; i <= 50; i+=2){
		sg[i] = i / 2;
	}
}

int n, num;

int main()
{
	getsg();
	while(~scanf("%d", &n)){
		int res = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &num);
			res ^= sg[num];
		}
		if(res != 0){
			printf("Yes\n");
		}
		else printf("No\n");
	}
	return 0;
}

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n, num[110];
struct node{
	int num, idx;
};
node no[110];

bool cmp(node no1, node no2){
	return no1.num > no2.num;
}

int main()
{
	while(~scanf("%d", &n) && n){
		for (int i = 0; i < n; i++){
			scanf("%d", &num[i]);
			no[i].num = abs(num[i]);
			no[i].idx = i;
		}
		sort(no, no + n, cmp);
		for (int i = 0; i < n; i++){
			printf("%d", num[no[i].idx]);
			if(i != n-1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node{
	char s[20];
	int cnt;
}boll[1010];

bool cmp(node no1, node no2){
	return no1.cnt > no2.cnt;
}
int n;
char col[20];
int main()
{
	while(scanf("%d", &n), n){
		int total = 0;
		for (int i = 0; i < n; i++){
			scanf("%s", col);
			bool flag = false;
			for (int j = 0; j < total; j++){
				if(!strcmp(col, boll[j].s)){
					boll[j].cnt++;
					flag = true;
					break;
				}
			}
			if(!flag){
				int len = strlen(col);
				for (int i = 0; i <= len; i++){
					boll[total].s[i] = col[i];
				}
				boll[total++].cnt = 1;
			}
		}
		sort(boll, boll+total, cmp);
		printf("%s\n", boll[0].s);
	}
	return 0;
}
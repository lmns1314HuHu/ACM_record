#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;

int main()
{
	while(~scanf("%d%d", &n, &m)){	
		double num[55][10];
		double stu[55];
		int cnt[55];
		double course[10];
		
		memset(cnt, 0, sizeof cnt);//要注意初始化！
		memset(course, 0, sizeof course);
		memset(num, 0, sizeof num);
		memset(stu, 0, sizeof stu);
		
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				scanf("%lf", &num[i][j]);
				stu[i] += num[i][j];
			}
			stu[i] /= m;
		}
		
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				course[i] += num[j][i];
			}
			course[i] /= n;
			for (int j = 0; j < n; j++){
				if(num[j][i] >= course[i]){
					cnt[j]++;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++){
			if(cnt[i] >= m){
				res ++;
			}
		}
		for (int i = 0; i < n; i++){
			printf("%.2lf", stu[i]);
			if(i != n-1) printf(" ");
			else printf("\n");
		}
		for (int i = 0; i < m; i++){
			printf("%.2lf", course[i]);
			if(i != m-1) printf(" ");
			else printf("\n");
		}
		printf("%d\n\n", res);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int sg[1000];
bool visit[1000];
void getsg(){
	memset(sg, 0, sizeof sg);
	sg[0] = 0;
	sg[1] = 1;
	sg[2] = 2;
	for (int i = 3; i < 1000; i++){
		memset(visit, 0, sizeof visit);
		for (int j = 0; j < i; j++){
			visit[sg[j]] = true;
		}
		for(int j = 1; j < i; j++){
			for (int k = 1; j+k < i; k++){
				int l = i-j-k;
				int yihuo = sg[j]^sg[k]^sg[l];
				visit[yihuo] = true;
			}
		}
		for (int j = 0; j < 1000; j++){
			if(!visit[j]){
				sg[i] = j;
				break;
			}
		}
	}
	for (int i = 0; i < 100; i++){
		cout << "sg[i] = " << i << " " << sg[i] << endl;
	}
}

int t, n, num;

int main()
{
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int res = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &num);
			if(num > 0 && num % 8 == 0){
				res ^= num-1;
			}
			else if(num > 0 && num % 8 == 7){
				res ^= num+1;
			}
			else res ^= num;
		}
		if(res != 0)
			printf("First player wins.\n");
		else printf("Second player wins.\n");
	}
	return 0;
}
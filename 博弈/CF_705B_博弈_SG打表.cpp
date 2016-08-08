#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int num;
int sg[1000];
bool visit[1000];

void getsg(){
	sg[1] = 0;
	sg[0] = 0;
	for (int i = 2; i < 1000; i++){
		memset(visit, 0, sizeof visit);
		for (int j = 1; j < i; j++){
			int k = i - j;
			int tmp = (sg[j] ^ sg[k]);
			visit[tmp] = true;
		}
		for (int j = 0; true; j++){
			if(!visit[j]){
				sg[i] = j;
				break;
			}
		}
	}
	//for (int i = 0; i < 100; i++){
		//cout << "i = " << i << " " << sg[i] << endl;
	//}
}

int main()
{
	scanf("%d", &n);
	int res = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &num);
		int tmp;
		if(num % 2 == 0)tmp = 1;
		else tmp = 0;
		res ^= tmp;
		if(res != 0) printf("1\n");
		else printf("2\n");
	}
	return 0;
}

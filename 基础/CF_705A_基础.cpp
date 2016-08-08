#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
typedef long long ll;

int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		if(i % 2 == 0){
			printf("I hate ");
		}
		else{
			printf("I love ");
		}
		if(i != n-1)
			printf("that ");
		else printf("it\n");
	}
	return 0;
}

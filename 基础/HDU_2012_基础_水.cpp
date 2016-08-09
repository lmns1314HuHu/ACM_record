#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool isPrime(int num){
	if(num <= 1)
		return false;
	for (int i = 2; i*i <= num; i++)
		if(num % i == 0)
			return false;
	return true;
}

int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		if(n==0 && m==0) break;
		if(n > m) swap(n, m);
		bool flag = false;
		for (int i = n; i <= m;	i++){
			int tmp = i*i+i+41;
			if(!isPrime(tmp)){
				flag = true;
				break;
			}
		}
		if(flag) printf("Sorry\n");
		else printf("OK\n");
	}
	return 0;
}
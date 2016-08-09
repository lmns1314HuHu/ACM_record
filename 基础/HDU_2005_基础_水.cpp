#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int tian[] = {31,28,31,30,31,30,
				31,31,30,31,30,31};
				
bool isLeap(int year){
    if((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}

int main()
{
	int y, m, d;
	while(~scanf("%d/%d/%d", &y, &m, &d)){
		int res = 0;
		for (int i = 0; i < m-1; i++){
			res += tian[i];
		}
		res += d;
		if(m > 2 && isLeap(y))
			res ++;
		printf("%d\n", res);
	}
	return 0;
}
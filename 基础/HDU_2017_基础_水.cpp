#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	string st;
	int t;
	scanf("%d", &t);
	getchar();
	while(t--){
		getline(cin, st);
		int cnt = 0;
		for (int i = 0; i < st.length(); i++){
			if(st[i] >= '0' && st[i] <= '9')
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
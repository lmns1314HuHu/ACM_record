#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char jishu[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

int main()
{
	int n, r;
	while(~scanf("%d%d", &n, &r)){
		bool fu = false;
		stack<char> stk;
		if(n < 0){
			fu = true;
			n *= -1;
		}
		if(fu) printf("-");
		while(n != 0){
			int tmp = n % r;
			stk.push(jishu[tmp]);
			n /= r;
		}
		if(stk.size() == 0)printf("0\n");
		else {
			while(!stk.empty()){
				printf("%c", stk.top());
				stk.pop();
			}
			printf("\n");
		}
	}
	return 0;
}
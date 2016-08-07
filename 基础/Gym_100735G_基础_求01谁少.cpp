#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[100010];

int main()
{
    while(~scanf("%s", s)){
        int num1 = 0;
        int num0 = 0;
        int len = strlen(s);
        for (int i = 0; i < len; i++){
            if(s[i] == '1') num1++;
            else num0++;
        }
        printf("%d\n", min(num1,num0));
    }
    return 0;
}

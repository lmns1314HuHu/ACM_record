#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char str[100010];

int main()
{
    while(~scanf("%s", str)){
        int len = strlen(str);
        for (int i = 0; i < len; i++){
            cout << str[i];
        }
        for (int i = len-1; i >= 0; i--){
            cout << str[i];
        }
        cout << endl;
    }
    return 0;
}

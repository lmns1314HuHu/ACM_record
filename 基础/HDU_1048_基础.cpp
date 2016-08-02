/**==================================
 | Author: YunHao
 | OJ: HDU
 | Kind: 水题
 | Date: 2016/8/1
 | Describe:
 |          
 |          
 =================================**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int main()
{
    string s, ss, se;
    while(getline(cin, ss)){
        if(ss == "ENDOFINPUT") break;
        getline(cin, s);
        getline(cin, se);
        for (int i = 0; i < s.length(); i++){
            if(isalpha(s[i])){
                printf("%c", (char)('A' + (s[i] - 'A' + 21) % 26));
            }
            else printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}

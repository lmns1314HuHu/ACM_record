#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
char st[10010];

int main()
{
    scanf("%d", &n);
    while(n--){
        scanf("%s", st);
        int len = strlen(st);
        int cnt = 1;
        char rem = st[0];
        for (int i = 1; i < len; i++){
            if(st[i] == rem) cnt++;
            else{
                if(cnt == 1)
                    printf("%c", rem);
                else 
                    printf("%d%c",cnt, rem );
                cnt = 1;
                rem = st[i];
            }
        }
        if(cnt == 1)
            printf("%c\n", rem);
        else 
            printf("%d%c\n", cnt, rem);
    }
    return 0;
}

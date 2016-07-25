#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int t;
char shu[10000010];

bool cmp(char ch1, char ch2){
    return ch1 > ch2;
}

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%s", shu);
        int len = strlen(shu);
        if(len < 2){
            printf("Uncertain\n");
            continue;
        }
        sort(shu, shu+len, cmp);
        int cnt = 0, jinwei=0, idx = -1;
        for (int i = len-1; i>= 0; i--){
            if(shu[i] != '0'){
                if(jinwei == 0){
                    jinwei = shu[i]-'0';
                    idx = i;
                }
                cnt++;
            }
            if(cnt > 1){
                break;
            }
        }
        if(cnt < 2){
            printf("Uncertain\n");
            continue;
        }
        for (int i = len-1; i>= 0; i--){
            if(i == idx)continue;
            int he = shu[i]-'0'+jinwei;
            int yu = he % 10;
            jinwei = he / 10;
            shu[i] = yu+'0';
        }
        if(jinwei != 0)
            printf("%d", jinwei);
        shu[idx]='\0';
        printf("%s",shu);
        printf("%s", shu+idx+1);
        printf("\n");
    }
    return 0;
}

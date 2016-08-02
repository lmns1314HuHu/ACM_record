#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define next nxt
using namespace std;
typedef long long ll;

int next[50010];
int ex[50010];

void exkmp(char s1[], char s2[], int next[], int ex[]){
    int i, j, p;
    for (i = 0, j = 0, p = -1; s1[i] != '\0'; i++, j++, p--){
        if(p == -1){
            j = 0;
            do
                p++;
            while(s1[i+p] != '\0' && s1[i+p] == s2[j+p]);
            ex[i] = p;
        }
        else if(next[j] < p)
            ex[i] = next[j];
        else if(next[j] > p)
            ex[i] = p;
        else{
            j = 0;
            while(s1[i + p] != '\0' && s1[i+p] == s2[j+p]) p++;
            ex[i] = p;
        }
    }
    ex[i] = 0;
}

int main()
{
    char s1_p[50010];
    char s2_s[50010];
    while(~scanf("%s", s1_p)){
        scanf("%s", s2_s);

        next[0] = 0;
        exkmp(s1_p + 1, s1_p, next, next+1);
        exkmp(s2_s, s1_p, next, ex);

        int len = strlen(s2_s);
        int mx = 0, mx_index = -1;
        for (int i = 0; i <= len; i++){
            if(ex[i] == len - i){
                if(ex[i] > mx){
                    mx = ex[i];
                    mx_index = i;
                }
            }
        }

        if(mx == 0){
            printf("0\n");
        }
        else{
            for (int i = mx_index; i < len; i++){
                printf("%c", s2_s[i]);
            }
            printf(" %d\n", mx);
        }
    }
    return 0;
}

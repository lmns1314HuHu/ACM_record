/**==================================
 | Author: YunHao
 | OJ: 
 | Kind: 
 | Date: 
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

int n;
char s1[10010];
char s2[10010];
int num1[150];
int num2[150];
int nxt1[10010];
int nxt2[10010];
int ex1[10010];
int ex2[10010];

bool cmp(int* num1, int* num2){
    for (int i = 0; i < 150; i++){
        if(num1[i] != num2[i])
            return false;
    }
    return true;
}

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
    while(~scanf("%s", s1)){
        scanf("%s", s2);
        memset(num1, 0, sizeof num1);
        memset(num2, 0, sizeof num2);

        nxt1[0] = 0;
        exkmp(s1 + 1, s1, nxt1, nxt1 + 1);
        exkmp(s2, s1, nxt1, ex2);

        nxt2[0] = 0;
        exkmp(s2 + 1, s2, nxt2, nxt2 + 1);
        exkmp(s1, s2, nxt2, ex1);

        int len1 = strlen(s1), len2 = strlen(s2);

        for (int i = 0; i < len1; i++){
            num1[s1[i]]++;
            num2[s2[i]]++;
            if(cmp(num1, num2)){
                bool flag = false;
                for (int j = 0; j <= i; j++){
                    if(ex2[j] < i - j + 1) continue;
                    if(ex1[i - j + 1] < j) continue;
                    flag = true;
                    break;
                }
                if(flag) printf("1");
                else printf("0");
            }
            else{
                printf("0");
            }
        }
        printf("\n");
    }
    return 0;
}

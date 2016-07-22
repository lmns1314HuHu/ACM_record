#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 100010

char st2[maxn];
char st1[maxn];
int nxt1[maxn];
int nxt2[maxn];

void getnext(int* nxt, char* st){
    int i = 0, j = -1;
    nxt[0] = -1;
    int n = strlen(st);
    while(i <= n){
        while(j >= 0 && st[i] != st[j])
            j = nxt[j];
        i++; j++;
        nxt[i] = j;
    }
}

int main()
{
    while(~scanf("%s", st1)){
        scanf("%s", st2);

        getnext(nxt1, st1);
        int n1 = strlen(st1);
        int mi_time1 = n1 / (n1 - nxt1[n1]);
        int mi_len1 = n1-nxt1[n1];
        if(n1 % mi_len1 != 0)
            mi_len1 = n1;

        getnext(nxt2, st2);
        int n2 = strlen(st2);
        int mi_time2 = n2 / (n2 - nxt2[n2]);
        int mi_len2 = n2-nxt2[n2];
        if(n2 % mi_len2 != 0)
            mi_len2 = n2;

        int len_cmp = max(mi_len1, mi_len2);
        bool flag = false;

        //cout << "changdu1=" << mi_len1 << " mi_time1=" << mi_time1 << endl;
        //for (int i = 0; i <= n1; i++){
            //cout << nxt1[i] << " ";
        //}
        //cout << endl;
        //cout << "changdu1=" << mi_len2 << " mi_time2=" << mi_time2 << endl;
        //for (int i = 0; i <= n2; i++){
            //cout << nxt2[i] << " ";
        //}
        //cout << endl;

        for (int i = 0; i < len_cmp; i++){
            if(st1[i] != st2[i]){
                flag = true;
                break;
            }
        }
        if(flag){
            printf("0\n");
            //cout << "hehe" << endl;
            continue;
        }
        int res = 0, i = 1;
        while(n1 / i / mi_len1 > 0 && n2 / i / mi_len1 > 0){
            if(n1 % (i * mi_len1) == 0 && n2 % (i * mi_len1) == 0)
                res++;
            i++;
        }
        printf("%d\n", res);
    }
    return 0;
}

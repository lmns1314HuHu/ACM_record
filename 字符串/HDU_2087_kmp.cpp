#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char t[1010];
char p[1010];
int nexta[1010];
int cnt, n, m;

void getnext(){
    nexta[0] = -1;
    int i = 0, j = -1;
    while(i < m){
        while(j >= 0 && p[i] != p[j]) j = nexta[j];
        j++; i++;
        if(p[i]==p[j]) nexta[i] = nexta[j];
        else nexta[i] = j;
    }
}

void kmp(){
    int i = 0, j = 0;
    while(i < n){
        while(j >= 0 && t[i] != p[j]){
            j = nexta[j];
        }
        i++; j++;
        if(j == m){
//            printf("%d\n", i-m);
            cnt++;
            //j = next[m];
            j = 0;
//            cout << "i=" << i << " j=" << j << " nextj=" << next[j] << endl;
        }
    }
}

void getnext2(){
    nexta[0] = -1;
    int i = 0, j = -1;
    while(i < m){
        while(j >= 0 && p[i] != p[j]) j = nexta[j];
        j++; i++;
        nexta[i] = j;
    }
}

int main()
{
    while(~scanf("%s", t)){
        if(t[0] == '#') break;
        scanf("%s", p);
        getnext();
        cnt = 0;
        n = strlen(t);
        m = strlen(p);
        kmp();
        printf("%d\n", cnt);
    }
    return 0;
}

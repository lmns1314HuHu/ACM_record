#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int tt, n, m;
int t[1000010];
int p[10010];
int nxt[10010];
void getnext(){
    nxt[0] = -1;
    int i=0,j=-1;
    while(i<m){
        while(j>=0 && p[i]!=p[j]) j=nxt[j];
        i++;j++;
        if(p[i]==p[j])nxt[i]=nxt[j];
        else nxt[i]=j;
    }
}

int kmp(){
    int i=0,j=0;
    while(i<n){
        while(j>=0 && t[i]!=p[j]){
            j=nxt[j];
        }
        i++;j++;
        if(j==m){
//            printf("%d\n", i-m);
            return i-m+1;
        }
    }
    return -1;
}

int main()
{
    scanf("%d", &tt);
    while(tt--){
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++){
            scanf("%d", &t[i]);
        }
        for (int i = 0; i < m; i++){
            scanf("%d", &p[i]);
        }
        getnext();
        int res = kmp();
        printf("%d\n", res);
    }
    return 0;
}

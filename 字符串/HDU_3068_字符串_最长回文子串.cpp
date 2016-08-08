#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char str[222000];
char t[222000];
int R[222000];
int mx;

void manacher(char* t, int l){
    int pos = 0, MaxRight = 0;
    for (int i = 1; i < l; i++){
        if(MaxRight > i)
            R[i] = min(R[2*pos-i], MaxRight - i + 1);
        else R[i] = 1;
        while(t[i+R[i]] == t[i-R[i]]) R[i]++;
        if(R[i] - 1 > mx) mx = R[i] - 1;
        if(R[i] + i - 1 > MaxRight){
            MaxRight = R[i] + i - 1;
            pos = i;
        }
    }
}

int main()
{
    while(~scanf("%s", str)){
        int j = 0;
        //memset(t, '\0', sizeof t);
        t[j++] = '@';
        t[j++] = '$';
        int len = strlen(str);
        for (int i = 0; i < len; i++){
            t[j++] = str[i];
            t[j++] = '$';
        }
        t[j++] = '\0';
        mx = 0;
        manacher(t, j);
        printf("%d\n", mx);
    }
    return 0;
}

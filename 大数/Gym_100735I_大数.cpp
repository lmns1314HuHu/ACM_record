#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char a[3][110];

char he[110];
void add(char* a, char* b){
    int lena = strlen(a);
    int lenb = strlen(b);
    int jinwei = 0;
    int ia = lena-1, ib = lenb-1;
    int chang = max(lena, lenb);
    he[chang+1] = '\0';
    while(ia>=0 && ib>=0 && chang >= 0){
        int zong = a[ia]-'0' + b[ib]-'0' + jinwei;
        int sheng = zong % 10;
        jinwei = zong / 10;
        he[chang] = sheng + '0';
        chang--;ia--;ib--;
    }
    while(ia >= 0){
        int zong = a[ia]-'0'+jinwei;
        int sheng = zong % 10;
        jinwei = zong / 10;
        he[chang] = sheng + '0';
        chang--;ia--;
    }
    while(ib >= 0){
        int zong = b[ib]-'0' + jinwei;
        int sheng = zong % 10;
        jinwei = zong / 10;
        he[chang] = sheng + '0';
        chang--;ib--;
    }
    he[chang] = jinwei+'0';
}

bool cmp(char* a, char* b){
    if(a[0] == '0'){
        return strcmp(a+1, b);
    }
    return strcmp(a, b);
}

int main()
{
    while(~scanf("%s", a[0])){
        scanf("%s", a[1]);
        scanf("%s", a[2]);

        bool flag = false;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                for (int k = 0; k < 3; k++){
                    add(a[j], a[k]);
                    if(!cmp(he, a[i])){
                        flag = true;
                        break;
                    }
//                    cout << he << endl;
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

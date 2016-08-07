#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

int t, n;
char st[110];

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        scanf("%s", st);
        int sheng = n;
        int zuo = 0;
        int you = 0;
        int res = 0;
        bool flag = false;
        for (int i = 0; i < n; i++){
            //cout << zuo <<" "  << sheng << endl;
            if(flag){
                //cout << "haha" << endl;
                if(st[i] != ')'){
                    res++;
                    //cout << i << endl;
                }
                continue;
            }
            if(zuo == sheng){
                //cout << "haha" << endl;
                //cout << i << endl;
                if(st[i] != ')')
                    res++;
                flag = true;
            }
            if(st[i] == '('){
                zuo++;
                sheng--;
            }
            else if(st[i] == ')'){
                if(zuo != 0){
                    zuo--;
                    sheng--;
                }
                else{
                    res++;
                    //cout << i << endl;
                    zuo++;
                    sheng--;
                }
            }
            //sheng--;
        }
        printf("%d\n", res);
    }
    return 0;
}

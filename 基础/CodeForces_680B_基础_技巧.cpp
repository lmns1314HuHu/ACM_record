#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, a;
int num[110];

int main()
{
    while(~scanf("%d%d", &n, &a)){
        for (int i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }
        a--;
        int res = num[a];
        int zhong = a;
        for (int i = 1; i < n; i++){
            if(zhong + i < n && zhong -i >= 0){
                if(num[zhong+i]+num[zhong-i] == 2){
                    res += 2;
                }
            }
            else if(zhong+i <= n-1){
                res += num[zhong + i];
            }
            else if(zhong -i >= 0){
                res += num[zhong - i];
            }
        }
        printf("%d\n", res);    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n,a,p[maxn];
int main()
{
    scanf("%d%d",&n,&a);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    int ans = p[a];
    for(int i=0,l=a-1,r=a+1;l>=1||r<=n;l--,r++){
        if(l>=1&&r<=n){
            if(p[l]&&p[r])ans+=2;
        }
        else if(l>=1)ans+=p[l];
        else if(r<=n)ans+=p[r];
    }
    cout<<ans<<endl;
}

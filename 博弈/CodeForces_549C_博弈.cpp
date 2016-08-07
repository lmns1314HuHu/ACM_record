#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, k, cnt,num1,num2;

int main()
{
    while(~scanf("%d%d", &n, &k))
    {
        cnt = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &num2);
            if(num2 % 2 == 1) cnt++;
        }
//        for ( int i = 0 ; i < n ; i++ )
//        {
//            scanf ( "%d" , &num2 );
//            if ( num2&1 ) cnt++;
//        }
        num2 = (n-k)/2;
        num1 = (n-k+1)/2;
        bool flag = true;
        if (cnt <= num2)
            flag = false;
        if (k % 2 == 0 && n - cnt <= num2)
            flag = false;
        if ((n-k) % 2 != 1)
        {
            if ( num1 >= n - cnt && k%2 == 1 );
            else flag = false;
        }
//        else
//        {
//            if ( num1 >= n - cnt && k%2 == 1 );
//            else flag = false;
//        }
        if (n == k){
            if(cnt % 2 == 1){
                flag = true;
            }
            else flag = false;
        }
//        for (int i = 0; i < n; i++){
//
//        }
        if (flag) printf("Stannis\n");
        else printf("Daenerys\n");

    }
}

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s1[5000], s2[5000];

//longest common sequence
int dp[1000][1000];

int main()
{
    while(~scanf("%s %s", s1, s2)){
        memset(dp, 0, sizeof(dp));
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        for (int i = 0; i < len1; i++){
            for (int j = 0; j < len2; j++){
                if(s1[i] == s2[j])
                    dp[i+1][j+1] = dp[i][j]+1;
                else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
//        for (int i = 0; i <= len1; i++){
//            for (int j = 0; j <= len2; j++){
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
        printf("%d\n", dp[len1][len2]);
    }
    return 0;
}

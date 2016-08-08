/**==================================
 | Author: YunHao
 | OJ: 
 | Kind: 
 | Date: 
 | Describe:我们把棋子按位置升序排列后，从后往前把他们两两绑定成一对。如果总个数是奇数，就把最前面一个和边界（位置为0）绑定。 
 |          在同一对棋子中，如果对手移动前一个，你总能对后一个移动相同的步数，所以一对棋子的前一个和前一对棋子的后一个之间有
 |          多少个空位置对最终的结果是没有影响的。于是我们只需要考虑同一对的两个棋子之间有多少空位。我们把每一对两颗棋子的距
 |          离(空位数)视作一堆石子，在对手移动每对两颗棋子中靠右的那一颗时，移动几位就相当于取几个石子,与取石子游戏对应上了,
 |          各堆的石子取尽,就相当再也不能移动棋子了。
 =================================**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

int t, n;
int num[1010];
int shizi[1010];

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int cur = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }
        sort(num, num + n);
        for (int i = n-1; i > 0; i-=2){
            shizi[cur++] = num[i] - num[i-1]-1;
        }
        if(n % 2 == 1)
            shizi[cur++] = num[0]-1;
        int res = 0;
        for (int i = 0; i < cur; i++){
            res ^= shizi[i];
        }
        if(res != 0)
            printf("Georgia will win\n");
        else printf("Bob will win\n");
    }
    return 0;
}

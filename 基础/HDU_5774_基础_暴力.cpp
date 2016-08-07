#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

string str[] = {
	"Cleveland Cavaliers",
	"Golden State Warriors",
	"San Antonio Spurs",
	"Miami Heat",
	"Miami Heat",
	"Dallas Mavericks",
	"L.A. Lakers",
	"L.A. Lakers",
	"Boston Celtics",
	"San Antonio Spurs",
	"Miami Heat",
	"San Antonio Spurs",
	"Detroit Pistons",
	"San Antonio Spurs",
	"L.A. Lakers",
	"L.A. Lakers",
	"L.A. Lakers",
	"San Antonio Spurs",
	"Chicago Bulls",
	"Chicago Bulls",
	"Chicago Bulls",
	"Houston Rockets",
	"Houston Rockets",
	"Chicago Bulls",
	"Chicago Bulls",
	"Chicago Bulls",
	"Detroit Pistons",
	"Detroit Pistons",
	"L.A. Lakers",
	"L.A. Lakers",
	"Boston Celtics",
	"L.A. Lakers",
	"Boston Celtics",
	"Philadelphia 76ers",
	"L.A. Lakers",
	"Boston Celtics",
	"L.A. Lakers",
	"Seattle Sonics",
	"Washington Bullets",
	"Portland Trail Blazers",
	"Boston Celtics",
	"Golden State Warriors",
	"Boston Celtics",
	"New York Knicks",
	"L.A. Lakers",
	"Milwaukee Bucks",
	"New York Knicks",
	"Boston Celtics",
	"Boston Celtics",
	"Philadelphia 76ers",
	"Boston Celtics",
	"Boston Celtics",
	"Boston Celtics",
	"Boston Celtics",
	"Boston Celtics",
	"Boston Celtics",
	"Boston Celtics",
	"Boston Celtics",
	"St. Louis Hawks",
	"Boston Celtics",
	"Philadelphia Warriors",
	"Syracuse Nats",
	"Minneapolis Lakers",
	"Minneapolis Lakers",
	"Minneapolis Lakers",
	"Rochester Royals",
	"Minneapolis Lakers",
	"Minneapolis Lakers",
	"Baltimore Bullets",
	"Philadelphia Warriors"
};

struct node{
    string s;
    int cnt;
}no[70];

int t;
string haha;

int main()
{
    int k = 0;
    for (int i = 0; i < 70; i++){
        no[i].s = "";
        no[i].cnt = 0;
    }
    for (int i = 0; i < 70; i++){
        bool flag = false;
        for (int j = 0; j < k; j++){
            if(no[j].s == str[i]){
                no[j].cnt++;
                flag = true;
                break;
            }
        }
        if(!flag){
            no[k].s = str[i];
            no[k++].cnt = 1;
        }
    }
    scanf("%d\n", &t);
    for(int w = 1; w <= t; w++){
        getline(cin , haha);
        bool check = false;
        for (int i = 0; i < k; i++){
            if(no[i].s == haha){
                check = true;
                printf("Case #%d: %d\n", w, no[i].cnt);
                break;
            }
        }
        if(!check)
            printf("Case #%d: 0\n", w);
    }
    return 0;
}

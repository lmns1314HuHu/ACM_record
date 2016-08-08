#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxnode 1000005
#define sigma_size 26

int cnt;
int t, n;
char st[1000005];

struct Trie{
    int ch[maxnode][sigma_size];
    //int val[maxnode];
    int sz;
    Trie(){
        sz = 1;
        memset(ch, 0, sizeof(ch[0]));
    }
    int idx(char c){
        return c-'a';
    }
    void insert(char* s){
        int u = 0, n = strlen(s);
        bool flag = false;
        for (int i = 0; i < n; i++){
            if(!flag) cnt++;
            int c = idx(s[i]);
            if(!ch[u][c]){
                memset(ch[sz], 0, sizeof(ch[sz]));
                //val[sz] = 0;
                ch[u][c] = sz++;
                flag = true;
            }
            u = ch[u][c];
        }
        //val[u] = v;
    }
};

int main()
{
    scanf("%d", &t);
    for(int w = 1; w <= t; w++){
        scanf("%d", &n);
        cnt = 0;
        Trie* root = new Trie();
        for (int i = 0; i < n; i++){
            scanf("%s", st);
            root->insert(st);
        }
        printf("Case #%d: %d\n", w, cnt);
        delete root;
    }
    return 0;
}

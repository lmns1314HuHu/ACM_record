#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxnode 1000000
#define sigma_size 26

struct Trie{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int cnt[maxnode];
    int sz;
    Trie(){
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset(cnt, 0, sizeof cnt);
    }

    int idx(char c){
        return c - 'a';
    }

    void add(char* s, int v){
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++){
            int c = idx(s[i]);
            cnt[u]++;
            if(!ch[u][c]){
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
        cnt[u]++;
    }

    int query(char *s){
        int l=strlen(s),u=0;
        for(int i=0;i<l;i++){
            int c = idx(s[i]);
            if(!ch[u][c]) return 0;
            u = ch[u][c];
        }
        return cnt[u];
    }
};

int main()
{
    char s[15];
    Trie* tr = new Trie();
    while(gets(s)){
        if(s[0] == '\0') break;
        tr->add(s, 1);
    }
    while(~scanf("%s", s)){
        printf("%d\n", tr->query(s));
    }
    delete tr;
    return 0;
}

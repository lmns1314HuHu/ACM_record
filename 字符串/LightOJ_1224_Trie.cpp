#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int t, n, mx;
#define maxnode 2500010
#define sigma_size 4
char st[55];

struct Trie{
	int ch[maxnode][sigma_size];
	int val[maxnode];
	int sz;
	int sum[maxnode];
	Trie(){
		sz = 1;
		memset(ch[0], 0, sizeof (ch[0]));
		memset(sum, 0, sizeof (sum));
	}
	int idx(char c){
		if(c == 'A')
			return 0;
		else if(c == 'C')
			return 1;
		else if(c == 'G')
			return 2;
		else if(c == 'T')
			return 3;
	}
	void _insert(char* s, int v){
		int u = 0, n = strlen(s);
		for (int i = 0; i < n; i++){
			int c = idx(s[i]);
			if(!ch[u][c]){
				memset(ch[sz], 0, sizeof(ch[sz]));
				val[sz] = 0;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
			sum[u]++;
		}
		val[u] = 1;
	}

	void _query(int u, int _depth){
		if(mx < sum[u] * _depth){
			mx = sum[u]*_depth;
		}
		for (int i = 0; i < 4; i++){
			if(ch[u][i]){
				_query(ch[u][i], _depth + 1);
			}
		}
	}

};

int main()
{
	scanf("%d", &t);
	for(int w = 1; w <= t; w++){
		scanf("%d", &n);
		Trie* tr = new Trie();
		for (int i = 0; i < n; i++){
			scanf("%s", st);
			tr->_insert(st, 1);
		}
		mx = 0;
		tr->_query(0, 0);
		printf("Case %d: %d\n",w, mx);
		delete tr;
	}
	return 0;
}

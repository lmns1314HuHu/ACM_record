#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define maxnode 3*10e5
#define sigma_size 3
int n, m;
char st[600010];

struct node{
	node* ch[sigma_size];
	int val;
	bool sign_for_destroy;
	node(){
		sign_for_destroy = false;
		val = 0;
		memset(ch, 0, sizeof ch);
	}
};
node* root;
queue< pair<node*, int> > q;

int idx(char c){
	return c-'a';
}

void _insert(node* no, char* s){
	int len = strlen(s);
	node* u = no;
	for (int i = 0; i < len; i++){
		int v = idx(s[i]);
		if(u->ch[v] == NULL){
			u->ch[v] = new node();
		}
		u = u->ch[v];
		u->sign_for_destroy = false;
	}
	u->sign_for_destroy = true;
	u->val = 1;
}

void _destroy(node* no){
	if(no->sign_for_destroy){
		delete no;
		return ;
	}
	for (int i = 0; i < sigma_size; i++){
		if(no->ch[i] != NULL){
			_destroy(no->ch[i]);
		}
	}
	delete no;
}

/*bool query(node* no, char* s){
	int len = strlen(s);
	node* u = no;
	for (int i = 0; i < len; i++){
		int v = idx(s[i]);
		if(u->ch[v] == NULL){
			return false;
		}
		u = u->ch[v];
	}
	if(u->val == 1)
		return true;
	else
		return false;
}*/

bool _find(node* no, char* s){
	while(q.size())q.pop();
	q.push(make_pair(no, 0));
	int cnt_q = 1;
	
	int len = strlen(s);
	for (int i = 0; i < len; i++){
		cnt_q = q.size();
		int v = idx(s[i]);
		if(q.size() == 0) return false;
		for (int j = 0; j < cnt_q; j++){
			node* fr = q.front().first;
			int cur_time = q.front().second;
			q.pop();
//			if(fr->sign_for_destroy){
//				break;
//			}
			for (int i = 0; i < 3; i++){
				if(fr->ch[i] == NULL) continue;
				if(i == v)
					q.push(make_pair(fr->ch[i], cur_time));
				else{
					if(cur_time < 1)
						q.push(make_pair(fr->ch[i], 1));
				}
			}
		}
	}
	while(!q.empty()){
		node* fr = q.front().first;
		int cur_time = q.front().second;
		q.pop();
		if(cur_time == 1 && fr->sign_for_destroy)
			return true;
	}
	return false;
}

int main()
{
	while(~scanf("%d%d", &n, &m)){
		root = new node();
		for (int i = 0; i < n; i++){
			scanf("%s", st);
			_insert(root, st);
		}
		for (int i = 0; i < m; i++){
			scanf("%s", st);
			if(_find(root, st))
				printf("YES\n");
			else 
				printf("NO\n");
		}
		_destroy(root);
	}
	return 0;
}

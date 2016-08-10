#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	string s;
	int n;
	cin >> n;
	getchar();
	while(n--){
		getline(cin, s);
		if(s[0] != '_' && !isalpha(s[0])){
			cout << "no" << endl;
		}
		else{
			bool flag = false;
			for (int i = 1; i < s.length(); i++){
				if(!isalnum(s[i]) && s[i] != '_'){
					flag = true;
					break;
				}
			}
			if(flag) cout << "no" << endl;
			else cout << "yes" << endl;
		}
	}
	return 0;
}
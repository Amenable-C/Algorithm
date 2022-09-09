#include <bits/stdc++.h>
using namespace std;

string s;
bool flag = 0;

int main(){
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(i < s.size() - 1 && s.substr(i, 2) == "pi" || s.substr(i, 2) == "ka")
			i += 1;
		else if(i < s.size() - 2 && s.substr(i, 3) == "chu")
			i += 2;
		else
			flag = 1;
	}
	if(flag)
		cout << "NO";
	else
		cout << "YES";
		
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

string s, boom;
string ret;

int main(){
	cin >> s;
	cin >> boom;
	
	
	while(s.find(boom) != -1){
		s = s.substr(0, s.find(boom)) + s.substr(s.find(boom) + boom.size());
	}
	
	
	if(s.size())
		cout << s;
	else
		cout << "FRULA";
	
	return 0;
}

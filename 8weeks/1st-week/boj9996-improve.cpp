#include <bits/stdc++.h>
using namespace std;

int n;
string s, ori, pre, suf;

int main(){
	cin >> n;
	cin >> ori;
	
	int star = ori.find('*');
	pre = ori.substr(0, star);
	suf = ori.substr(star + 1);
	
	for(int i = 0; i < n; i++){
		cin >> s;
		
		if(pre.size() + suf.size() > s.size()){
			cout << "NE" << endl;	
		}
		else{
			if(pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size()))
				cout << "DA" << endl;
			else
				cout << "NE" << endl;
		}
		
	}

}


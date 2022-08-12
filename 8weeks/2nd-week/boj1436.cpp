#include <bits/stdc++.h>
using namespace std;

long n;
string s;
vector<long> v;

int main(){
	cin >> n;
	
	long i = 666;
	for(;; i++){
		s = to_string(i);
		
		if(s.find("666") != string::npos)
			n--;
		
		if(n == 0)
			break;
		
	}
	
	cout << i;
}

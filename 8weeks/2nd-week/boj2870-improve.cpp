#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;
string s, ret;

void go(){
	while(true){
		if(ret.size() && ret.front() == '0')
			ret.erase(ret.begin());
		else
			break;
	
	}
	if(ret.size() == 0) // 계속 0으로 이루어진 경우 
		ret = "0";
	v.push_back(ret); // v에 계속 쌓기 
	ret = ""; // 다음꺼 준비
}


bool cmp(string a, string b){
	if(a.size() == b.size())
		return a < b; // 각 자리수 비교 
		
	return a.size() < b.size(); 
	
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		ret = "";
		for(int  j = 0; j < s.size(); j++){
			if(s[j] < 65) // 숫자일때 
				ret += s[j];
			else if(ret.size())
				go();
		}
		if(ret.size())
			go();
	}
	
	sort(v.begin(), v.end(), cmp);
	for(string i : v)
		cout << i << "\n";
	return 0;
	
}

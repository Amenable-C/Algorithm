#include<bits/stdc++.h>
using namespace std;

int n;
string s;

string check(int num){
	string ss = to_string(num);
	string answer = "";
	for(int i = 0; i < ss.size(); i++){
		if(ss[i] == '3' || ss[i] == '6' || ss[i] == '9')
			answer += "-";
	}
	return answer;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		string clap = check(i);
		if(clap != "")
			cout << clap << " ";
		else
			cout << i << " ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int n = 4;

int main(){
	string a[n] = {"���", "����", "����", "��"};
	for(int i = 0; i < (1 << n); i++){
		string ret = "";
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				ret += (a[j] + " ");
			}
		}
		cout << ret << '\n';
	}
	
	return 0;
}

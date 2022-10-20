#include<bits/stdc++.h>
using namespace std;

const int max_n = 70;
int n; 
char a[max_n][max_n];
string s;

string go(int y, int x, int size){
	if(size == 1)
		return string(1, a[y][x]);
	
	char flag = a[y][x];
	string ret = "";
	
	for(int i = y; i < y + size; i++){
		for(int j = x; j < x + size; j++){
			if(a[i][j] != flag){
				ret += "(";
				ret += go(y, x, size / 2);
				ret += go(y, x + size / 2, size / 2);
				ret += go(y + size / 2, x, size / 2);
				ret += go(y + size / 2, x + size / 2, size / 2);
				ret += ")";
				return ret;
			}
		}
	}
	
	return string(1, a[y][x]);
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < n; j++){
			a[i][j] = s[j];
		}
	}
	
	cout << go(0, 0, n);
	return 0;
}

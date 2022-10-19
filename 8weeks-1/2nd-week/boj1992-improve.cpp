#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
char a[101][101];

string quard(int y, int x, int size){
	if(size == 1)
		return string(1, a[y][x]);
	char b = a[y][x];
	string ret = "";
	bool flag = 0;
	
	for(int i = y; i < y + size; i++){
		for(int j = x; j < x + size; j++){
			if(a[i][j] != b){
				ret += '(';
				ret += quard(y, x, size / 2);	
				ret += quard(y, x + size / 2, size / 2);
				ret += quard(y + size / 2, x, size / 2);
				ret += quard(y + size / 2, x + size / 2, size / 2);
				ret += ')';
				return ret; // 하나라도 있으면 바로 그냥 분기하고 그리고 그 값을 return 하는거 // 해당 위치에서 분기를 하는게 아니라 y, x를 기준으로 분기 
			}
		}
	}
	return string(1, a[y][x]);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < n; j++){
			a[i][j] = s[j];
		}
	}
	
	cout << quard(0, 0, n) << "\n";
	return 0;
	
}

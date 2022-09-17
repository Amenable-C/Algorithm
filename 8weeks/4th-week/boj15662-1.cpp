#include<bits/stdc++.h>
using namespace std;

int t, k, a, b, l, r, cnt, ret;
string s[1004];

void rot(int pos, int dir){
	if(dir == 0){ // 2 3 4 1
		rotate(s[pos].begin(), s[pos].begin() + 1, s[pos].end());
	}
	else{ // 4 1 2 3
		rotate(s[pos].begin(), s[pos].begin() + s[pos].size() - 1, s[pos].end());
	}
}

int findL(int pos){
	for(int i = pos; i >= 1; i--){
		if(s[i][6] == s[i - 1][2])
			return i;
	}
	return 0;
}

int findR(int pos){
	for(int i = pos; i < t - 1; i++){
		if(s[i][2] == s[i + 1][6])
			return i;
	}
	return t - 1;
}


int main(){
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> s[i];	
	}
	
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> a >> b;
		a--;
		b = (b == -1 ? 0 : 1); // 0 -> 반시계, 1 -> 시계 
		
		l = findL(a);
		r = findR(a);
		
		cnt = 0;
		for(int j = a; j >= l; j--){
			rot(j, cnt % 2 == 0 ? b : !b);
			cnt++;
		}
		
		cnt = 1;
		for(int j = a + 1; j <= r; j++){
			rot(j, cnt % 2 == 0 ? b : !b);
			cnt++;	
		}
		
	}
	
	for(int i = 0; i < t; i++){
		if(s[i][0] == '1')
			ret++;
	}
	
	cout << ret;
}

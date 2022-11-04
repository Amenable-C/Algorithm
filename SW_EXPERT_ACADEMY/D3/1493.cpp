#include<bits/stdc++.h>
using namespace std;

int t, p1, p2, xx1, yy1, xx2, yy2, x, y, cnt = 1;
map<int, pair<int, int>> mp1;
map<pair<int, int>, int> mp2;

int main(){
	// 점 1000개 돌리기
	for(int i = 2; i < 1000; i++){
		for(int j = 1; j < i; j++){
			mp1[cnt] = {j, i - j};
			mp2[{j, i - j}] = cnt;
			cnt++;
			if(cnt == 100004)
				break;
		}
		if(cnt == 100004)
			break;
	}
	
	cin >> t;
	for(int _t = 1; _t <= t; _t++){
		cin >> p1 >> p2;
		
		tie(xx1, yy1) = mp1[p1];
		tie(xx2, yy2) = mp1[p2];
		
		x = xx1 + xx2;
		y = yy1 + yy2;
		
		cout << "#" << _t << " " << mp2[{x, y}] << "\n";
	}
	
	return 0;
}

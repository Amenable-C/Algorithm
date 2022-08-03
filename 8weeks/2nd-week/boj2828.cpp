#include <bits/stdc++.h>
using namespace std;

int n, m, j, point, left1, right1, ret, dis;

int main(){
	cin >> n >> m;
	
	left1 = 1;
	right1 = m; // 1부터 시작하는걸 고려
	
	cin >> j;
	
	if(m ==  1){
		for(int i = 0; i < j; i++){
			cin >> point;
			ret += abs(point - left1);
			left1 = point;
		}
		cout << ret;
		return 0;
	}
	
	for(int i = 0; i < j; i++){
		cin >> point;
		if(point > right1){
			dis = abs(right1 - point);
			ret += dis;
			right1 += dis;
			left1 += dis;
		}
		else if(point < left1){
			dis = abs(left1 - point);
			ret += dis;
			right1 -= dis;
			left1 -= dis;
		}
	}
	
	cout << ret;
	return 0;
	
}

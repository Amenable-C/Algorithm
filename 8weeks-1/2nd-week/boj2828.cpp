#include<bits/stdc++.h>
using namespace std;

int n, m, t, p, l, r, cnt;

int main(){
	cin >> n >> m >> t;
	
	l = 0;
	r = m;
	for(int i = 0; i < t; i++){
		cin >> p;
		if(p <= l){ // 왼쪽에 있는 경우 
			cnt += l - p + 1;
			l = p - 1;
			r = l + m;
			 
		}
		else if(p > r){ // 오른쪽에 있는 경우 
			cnt += p - r;
			r = p;
			l = p - m;
		}
	}
	cout << cnt;
	return 0;
}

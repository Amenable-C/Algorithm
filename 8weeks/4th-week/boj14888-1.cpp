#include <bits/stdc++.h>
using namespace std;

int n , a[15], pl, mi, mu, di, idx, cur;

int ret1 = -987654321;
int ret2 = 987654321;

void go(int idx, int cur, int plus, int minus, int multiple, int divide){
	if(idx == n - 1){
		ret1 = max(ret1, cur);
		ret2 = min(ret2, cur);
	}
	
	if(plus){
		go(idx + 1, cur + a[idx + 1], plus - 1, minus, multiple, divide);	
	}
	if(minus){
		go(idx + 1, cur - a[idx + 1], plus, minus - 1, multiple, divide);
	}
	if(multiple){
		go(idx + 1, cur * a[idx + 1], plus, minus, multiple - 1, divide);
	}
	if(divide){
		go(idx + 1, cur / a[idx + 1], plus, minus, multiple, divide - 1);
	}
	return;
}


int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];	
	}
	
	cin >>  pl >> mi >> mu >> di;
	
	go(idx, a[0], pl, mi, mu, di);
	
	cout << ret1 << "\n" << ret2;
	
	return 0;
}

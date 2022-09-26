#include<bits/stdc++.h>
using namespace std;

int n, a[12], b[4], plu, minu, mul, divi;

int ret1 = -987654321;
int ret2 = 987654321;

void go(int index, int cur, int plus, int minus, int multiple, int divide){
	if(index == n - 1){
		ret1 = max(ret1, cur);
		ret2 = min(ret2, cur);
		return;	
	}
	
	if(plus){
		go(index + 1, cur + a[index + 1], plus - 1, minus, multiple, divide);	
	}
	if(minus){
		go(index + 1, cur - a[index + 1], plus, minus - 1, multiple, divide);
	}
	if(multiple){
		go(index + 1, cur * a[index + 1], plus, minus, multiple - 1, divide);
	}
	if(divide){
		go(index + 1, cur / a[index + 1], plus, minus, multiple, divide - 1);
	}
	return;
}


int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> plu >> minu >> mul >> divi;
	go(0, a[0], plu, minu, mul, divi);
	cout << ret1 << "\n" << ret2;
	return 0;
}

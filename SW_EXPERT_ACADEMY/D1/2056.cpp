#include<bits/stdc++.h>
using namespace std;

int a[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int t, n, y, m, d;

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n;
		d = n % 100;
		m = (n / 100) % 100;
		y = n / 10000;
		
		if(m > 0 && m < 13 && d > 0 && d <= a[m-1]){
			printf("#%d %04d/%02d/%02d\n", i, y, m, d);
		}
		else 
			cout << "#" << i << " " << -1 << "\n";
	}
	return 0;
}

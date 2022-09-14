#include<bits/stdc++.h>
using namespace std;

long long n, a[100004], ret, d;

int main(){
	cin >> n;
	for(long long i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(long long i = 0; i < n; i++){
		d = find(a + i + 1, a + n, a[i]) - a;
		ret += d - i;
	}
	cout << ret;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n, s, e, x, ret;

int main(){
	cin >> n;
	
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];	
	}
	
	cin >> x;
	
	sort(a, a + n);
	
	e = n - 1;
	while(s < e){
		if(a[s] + a[e] == x){
			ret++;	
			s++;
			e--;
		}
		else if(a[s] + a[e] < x){
			s++;
		}
		else if(a[s] + a[e] > x){
			e--;
		}
	}
	cout << ret;
	return 0;
}


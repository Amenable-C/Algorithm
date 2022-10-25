#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n , d[100004], c[100004];

ll go(){
	ll low_cost = c[0];
	ll d_sum = 0;
	ll ret = 0;
	for(int i = 1; i < n; i++){
		d_sum += d[i-1];
		if(c[i] < low_cost || i == n - 1){
			ret += d_sum * low_cost;
			d_sum = 0;
			low_cost = c[i];
		}
	}
	return ret;
}

int main(){
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		cin >> d[i];	
	}
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	
	cout << go();
}

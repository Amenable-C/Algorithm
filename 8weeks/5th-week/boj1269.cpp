#include<bits/stdc++.h>
using namespace std;

int n, m, a[200004], b[200004], cnt;

bool go(int k){
	int	lo = 0;
	int hi = n;
	
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		if(a[mid] == k){
			return true;	
		}
		else if(a[mid] < k){
			lo = mid + 1;
		}
		else if(a[mid] > k){
			hi = mid - 1;
		}
		
	}
	return false;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];	
	}
	
	sort(a, a + n); 
	
	for(int i = 0; i < m; i++){
		cin >> b[i];
		if(go(b[i]))
			cnt++;	
	}
	
	cout << n + m - (cnt * 2);
	return 0;
}

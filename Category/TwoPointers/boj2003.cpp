#include<bits/stdc++.h>
using namespace std;

int n, m, a[10004], low = 1, hi = 1, ret, num;

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> num;
		a[i] = a[i-1] + num;
	}
	
	while(hi <= n){
		if(a[hi] - a[low - 1] == m){
			ret++;
			hi++;
		}
		else if(a[hi] - a[low] < m){
			hi++;	
		}
		else{
			low++;	
		}
	}
	cout << ret;
	return 0;
	
}

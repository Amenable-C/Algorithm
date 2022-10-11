#include<bits/stdc++.h>
using namespace std;

int n, m, a[15004], ret;

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];	
	}
	
	sort(a, a + n);
	
	for(int i = 0; i < n - 1; i++){
		int j = 0;
		while(a[i] + a[n - j - 1] >= m && i < n - j - 1){
			if(a[i] + a[n - j - 1] == m)
				ret++;
			j++;	
		}
	}
	cout << ret;
}

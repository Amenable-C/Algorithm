#include<bits/stdc++.h>
using namespace std;

int t, n, m, a[20004], b[20004], ret;

int main(){
	cin >> t;
	while(t--){
		ret = 0;
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < m; i++){
			cin >> b[i];
		}
		
		sort(b, b + m);
		
		for(int i = 0; i < n; i++){
			auto it = lower_bound(b, b + m, a[i]);
			
			if(*it == 0){
				ret +=  m;	
			}
			else{
				ret += it - b;
			}
		}
		cout << ret << "\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int t, n, x, y, scope[14], dis, ret;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	
	for(int i = 1; i <= 10; i++){
		scope[i] = pow(20 * i, 2);	
	}
	
	for(int _t = 1; _t <= t; _t++){
		ret = 0;
		cin >> n;		
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			dis = pow(x, 2) + pow(y, 2);
			
			for(int j = 1; j <= 10; j++){
				if(dis <= scope[j]){
					ret += 11 - j;
					break;
				}
			}
		}
		
		cout << "#" << _t << " " << ret << "\n";
	}
	return 0;
}

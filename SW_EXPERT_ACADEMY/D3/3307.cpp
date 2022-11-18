#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll t, n, a[1004], cnt, ret, standard;

int main(){
	cin >> t;
	for(int _t = 1; _t <= t; _t++){
		memset(a, 0, sizeof(a));
		ret = 0;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];	
		}
		
		for(int i = 0; i < n - 1; i++){
			standard = a[i];
			cnt = 1;
			for(int j = i + 1; j < n; j++){
				if(a[j] >= standard){
					cnt++;
					standard = a[j];
				}
			}
			ret = max(ret, cnt);
		}
		cout << "#" << _t << " " << ret << "\n";
	}
}

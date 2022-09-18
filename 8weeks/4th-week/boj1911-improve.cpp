#include<bits/stdc++.h>
using namespace std;
#define prev t

typedef long long ll;

ll n, m, idx, ret;

int main(){
	cin >> n >> m;
	vector<pair<int, int>> a(n);
	
	for(int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
		
	sort(a.begin(), a.end());
	
	for(int i = 0; i < n; i++){
		if(a[i].second <= idx)
			continue;
			
		if(idx < a[i].first){
			int b = (a[i].second - a[i].first) / m + ((a[i].second - a[i].first) % m ? 1 : 0);
			ret += b;
			idx = a[i].first + b * m;	
		}
		else{
			int b = (a[i].second - idx) / m + ((a[i].second - idx) % m ? 1 : 0);
			ret += b;
			idx = idx + b * m;
		}
	}
	cout << ret;
	return 0;
}

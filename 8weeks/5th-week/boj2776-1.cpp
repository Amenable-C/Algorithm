#include<bits/stdc++.h>
using namespace std;

int t, n, m, temp;

int check(int temp, vector<int> &v){
	int l = 0, r = v.size() - 1;
	
	while(l <= r){
		int mid = (l + r) / 2;
		if(temp > v[mid]){
			l = mid + 1;	
		}
		else if(temp == v[mid]){
			return 1;
		}
		else{
			r = mid - 1;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
	cin >> t;
	while(t--){
		vector<int> v;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> temp;
			v.push_back(temp);	
		}
		
		sort(v.begin(), v.end());
		
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> temp;
			cout << check(temp, v) << "\n";
		}
	}
	return 0;
}

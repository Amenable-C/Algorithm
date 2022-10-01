#include<bits/stdc++.h>
using namespace std;

int n, x, y, ret, s, e;
pair<int, int> p[1000004];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		p[i].first = x;
		p[i].second = y;
	}
	
	sort(p, p + n);
	
	s = p[0].first;
	e = p[0].second;
	for(int i = 1; i < n; i++){
		
		if(p[i].first <= e && p[i].second >= e){
			e = p[i].second;
		}
		else if(p[i].first > e){
			ret += (e - s);
			s = p[i].first;
			e = p[i].second;
		}
	}
	
	ret += e - s;
	
	cout << ret;
	return 0;
}

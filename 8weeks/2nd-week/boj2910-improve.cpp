#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int n, c, a[1004];

vector<pair<int, int>> v;
map<int, int> mp, mp_first;

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first){ // 카운트가 같은 경우 
		return mp_first[a.second] < mp_first[b.second]; // '뒤에꺼가 늦게 왔다.' 라는 것 
	}
	return a.first > b.first;
}



int main(){
	cin >> n >> c;
	
	for(int i = 0; i < n; i++){
		cin >> a[i]; // 해당 값을 a[i]에 넣기 
		mp[a[i]]++; // a[i]에 있는 해당값을 계속 counting하면서 map에 저장 
		
		if(mp_first[a[i]] == 0) // 이미 이전에 해당 값이 들어온게 있는지 파악 
			mp_first[a[i]] = i + 1; // 해당 값이 언제 첫번째로 들어왔는지 저장
	}
	
	for(auto it : mp){ // 카운트 순으로 정렬해야 하므로 second를 value로 지정 
		v.push_back({it.second, it.first}); // vector에 pair로 집어 넣음 
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(auto i : v){
		for(int j = 0; j < i.first; j++){
			cout << i.second << " ";	
		}
	}
	return 0;
}

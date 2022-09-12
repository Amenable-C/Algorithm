#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ret, temp;
stack<pair<ll, ll>> s;

int main(){
	cin >> n;
	for(int i = 0;  i < n; i++){
		cin >> temp;
		int cnt = 1; // cnt 초기화 
		while(s.size() && s.top().first <= temp){ // 올라가거나 같은 경우 
			ret += s.top().second; // 바로 옆에 사람을 나란히 쭉 보는거(이미 cnt로 높이가 같은걸 고려했기 때문에 cnt를 더해주면 됨) 
			if(s.top().first == temp){ // 같은 경우는 팩토리얼 고려 
				cnt = s.top().second + 1;
			}
			else{ // 
				cnt = 1;
			}
			s.pop();
		}
		
		if(s.size()) // 내려올때 // 앞에 있는 사람이 뒤에 사람을 내려다 볼 수 있으므로 cnt++; 
			ret++;
		
		s.push({temp, cnt});
	}
	
	cout << ret;
	return 0;
}

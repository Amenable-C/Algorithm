#include<bits/stdc++.h>
using namespace std;

int t, n, m, tree[200004], temp;
map<int, int> mp;

void update(int idx, int value){
	while(idx <= 200004){
		tree[idx] += value;
		idx += (idx & -idx);
	}
}

int sum(int idx){
	int ret = 0;
	while(idx > 0){
		ret += tree[idx];
		idx -= (idx & -idx);	
	}
	return ret;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while(t--){
		cin >> n >> m;
		memset(tree, 0, sizeof(tree));
		mp.clear();
		
		int update_idx = 100001; // 쌓은 행위를 왼쪽에 두는것으로 할려고 함 // 배열에서는 -를 사용할 수 없으므로 이동해야 함.  
		for(int i = 1; i <= n; i++){
			update(i + update_idx, 1); // 자신의 오른쪽 부분에 모두 1을 더해줌 => i가 쌓여있다는 것을 나타내는 것. 
			mp[i] = i + update_idx;	// i번째 cd의 위치??? 
		}
		
		for(int i = 0; i < m; i++){
			cin >> temp; // 이동할 CD 
			int idx = mp[temp]; // 영화 번호를 이용하여 해당 위치를 알아내기. 
			cout << sum(idx) - 1 << " "; // 얼마나 쌓여있는지 출력 // 일단 자기 자신 빼고, 왼쪽에 있는 것들 합쳐서 출력하는 것. 
			update(idx, -1); // 해당 CD를 뺀 경우 => 해당 위치부터 오른쪽(아래)에 -1 해주기 (쌓여있는 하나를 제거해준 경우) 
			update(--update_idx, 1); // 위에 쌓는 경우 // 최대 100001번 만큼 계속해서 쌓을 수 있음 // 이거 때문에 위체서 오른쪽으로 밀어서 시작한것. 
			mp[temp] = update_idx;	// 해당 영화 번호에 해당하는 위치를 다시 map에 저장.  
		}
		cout << "\n";
	}
}

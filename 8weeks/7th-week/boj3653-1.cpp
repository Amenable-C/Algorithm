#include<bits/stdc++.h>
using namespace std;

int t, n, m, tree[200004], temp;
map<int, int> mp;

void update(int i, int num){
	while(i < 200004){
		tree[i] += num;
		i += (i & -i);
	}
}


int sum(int i){
	int ans = 0;
	while(i > 0){
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
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
		
		int update_idx = 100001;
		for(int i = 1; i <= n; i++){
			mp[i] = i + update_idx;
			update(i + update_idx, 1);
		}
		
		for(int i = 0; i < m; i++){
			cin >> temp;
			int idx = mp[temp]; // À§Ä¡
			cout << sum(idx) - 1 << " "; 
			update(idx, -1);
			update(--update_idx, 1);
			mp[temp] = update_idx;
		}
		cout << "\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, a[11], m, temp, ret = INF, comp[11], visited[11];
vector<int> adj[11];

pair<int, int> dfs(int here, int value){
	visited[here] = 1;
	pair<int, int> ret = {1, a[here]}; // 개수, 구역의 인구수 
	
	for(int there : adj[here]){
		if(comp[there] != value)
			continue;
		if(visited[there])
			continue;
		pair<int, int> _temp = dfs(there, value);
		ret.first += _temp.first;
		ret.second += _temp.second;
	}
	
	return ret;	
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){ // 각 구역의 인구수 
		cin >> a[i];	
	}
	
	for(int i = 1; i <= n; i++){
		cin >> m;
		for(int j = 0; j < m; j++){ // 양방향으로 연결 
			cin >> temp;
			adj[i].push_back(temp);
			adj[temp].push_back(i);
		}
	}
	
	for(int i = 1; i < (1 << n) - 1; i++){ // 선택을 안하는거랑 모두 선택하는거를 제외한 것. 
		fill(comp, comp + 11, 0); 
		fill(visited, visited + 11, 0);
		
		int idx1 = -1, idx2 = -1; // 마지막으로 각 선거구에 들어간 구역을 확인하기 위한것. 
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				comp[j + 1] = 1; // 1이랑 0으로 구분해서 선거구를 나눔 
				idx1 = j + 1; 
			}
			else
				idx2 = j + 1;
		}
		pair<int, int> comp1 = dfs(idx1, 1); // 1 선거구 
		pair<int, int> comp2 = dfs(idx2, 0); // 0 선거구 
		if(comp1.first + comp2.first == n) // 두 선거구로 모든 구역이 나누어졌는지 확인 
			ret = min(ret, abs(comp1.second - comp2.second));
	}
	
	cout << (ret == INF ? -1 : ret);
	return 0;
	
}



#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, a[11], m, temp, ret = INF, comp[11], visited[11];
vector<int> adj[11];

pair<int, int> dfs(int here, int value){
	visited[here] = 1;
	pair<int, int> ret = {1, a[here]}; // ����, ������ �α��� 
	
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
	for(int i = 1; i <= n; i++){ // �� ������ �α��� 
		cin >> a[i];	
	}
	
	for(int i = 1; i <= n; i++){
		cin >> m;
		for(int j = 0; j < m; j++){ // ��������� ���� 
			cin >> temp;
			adj[i].push_back(temp);
			adj[temp].push_back(i);
		}
	}
	
	for(int i = 1; i < (1 << n) - 1; i++){ // ������ ���ϴ°Ŷ� ��� �����ϴ°Ÿ� ������ ��. 
		fill(comp, comp + 11, 0); 
		fill(visited, visited + 11, 0);
		
		int idx1 = -1, idx2 = -1; // ���������� �� ���ű��� �� ������ Ȯ���ϱ� ���Ѱ�. 
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				comp[j + 1] = 1; // 1�̶� 0���� �����ؼ� ���ű��� ���� 
				idx1 = j + 1; 
			}
			else
				idx2 = j + 1;
		}
		pair<int, int> comp1 = dfs(idx1, 1); // 1 ���ű� 
		pair<int, int> comp2 = dfs(idx2, 0); // 0 ���ű� 
		if(comp1.first + comp2.first == n) // �� ���ű��� ��� ������ ������������ Ȯ�� 
			ret = min(ret, abs(comp1.second - comp2.second));
	}
	
	cout << (ret == INF ? -1 : ret);
	return 0;
	
}



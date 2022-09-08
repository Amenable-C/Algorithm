#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b, visited[1004], cnt;
vector<int> v[1004];

void dfs(int here){
	visited[here] = 1;
	for(int there : v[here]){
		if(!visited[there]){
			dfs(there);	
		}
	}
	return;
}




int main(){
	cin >> t;
	while(t--){
		for(int i = 0; i < 1004; i++){
			v[i].clear();	
		}
		fill(visited, visited + 1004, 0);
		cnt = 0;
		
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);	
		}
		
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				dfs(i);
				cnt++;
			}
		}
		
		if(n - 1 == m && cnt == 1)
			cout << "tree\n";
		else
			cout << "graph\n";
	}
}

#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, ret, c[10004], visited[10004], cnt;
vector<int> adj[10004];

void dfs(int num){
	cnt++;
	visited[num] = 1;
	for(int i : adj[num]){
		if(visited[i])
			continue;
		dfs(i);
	}
	return;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;	
		adj[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++){
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		dfs(i);
		c[i] = cnt;
		ret = max(ret, cnt);
	}
	
	for(int i = 1; i <= n; i++){
		if(c[i] == ret){
			cout << i << " ";
		}
	}
	return 0;
}

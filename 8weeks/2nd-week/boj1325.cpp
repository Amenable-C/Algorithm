#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b;
vector<int> adj[100004];
int cnt;
int dp[10001];
int visited[10001];

int dfs(int here){
	visited[here] = 1;
	int ret = 1;
	for(int there : adj[here]){
		if(visited[there])
			continue;
		ret += dfs(there);
	}
	return ret;
}

int main(){
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		adj[b].push_back(a);
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		memset(visited, 0, sizeof(visited));
		dp[i] = dfs(i);
		cnt = max(cnt, dp[i]);
	}
	
	for(int i = 1; i <= n; i++){
		if(cnt == dp[i])
			cout << i << " ";
	}
}

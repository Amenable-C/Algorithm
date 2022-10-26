#include<bits/stdc++.h>
using namespace std;

int n, rm, ret, p, root;
vector<int> adj[54];

void dfs(int num){
	if(adj[num].size() == 0){
		ret++;
		return;
	}
	int sum = 0;
	for(int i : adj[num]){
		if(i == rm)
			continue;
		sum++;
		dfs(i);
	}
	if(sum == 0)
		ret++;
	return;		
}

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> p;	
		if(p == -1){
			root = i;
		}
			
		adj[p].push_back(i);
	}
	cin >> rm;
	if(rm == root){
		cout << 0;
		return 0;	
	}
	dfs(root);
	cout << ret;
	return 0;
}

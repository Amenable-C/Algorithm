#include<bits/stdc++.h>
using namespace std;

int n, m, v, a, b, visited[1004];
priority_queue<int, vector<int>, greater<int>> pq[1004];
priority_queue<int, vector<int>, greater<int>> pq2[1004];

void dfs(int num){
	visited[num] = 1;
	cout << num << " ";
	
	while(pq[num].size()){
		int nn = pq[num].top();
		pq[num].pop();
		
		if(visited[nn] == 0){
			dfs(nn);	
		}
	}
	return;
}

void bfs(int num){
	visited[num] = 1;
	queue<int> q;
	q.push(num);
	while(q.size()){
		int nn = q.front();
		q.pop();
		cout << nn << " ";
		
		while(pq2[nn].size()){
			int mm = pq2[nn].top();
			pq2[nn].pop();
			if(visited[mm] == 0){
				visited[mm] = 1;
				q.push(mm);
			}
		}
	}
}

int main(){
	cin >> n >> m >> v;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		pq[a].push(b);
		pq2[a].push(b);
		pq[b].push(a);
		pq2[b].push(a);
	}
	
	dfs(v);
	memset(visited, 0, sizeof(visited));
	cout << "\n";
	bfs(v);
}

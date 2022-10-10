#include<bits/stdc++.h>
using namespace std;

int V, E, K, u, v, w;
vector<pair<int, int>> adj[20001];
int dist[20001];
bool visited[20001];
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
	cin >> V >> E >> K;
	fill(dist, dist + 20001, INF); // 처음에 무한대로 설정하고 최단거리 계속해서 업데이트 
	for(int i = 0; i < E; i++){
		cin >> u >> v >> w; // 'u에서 v로 가는 가중치 w인 간선이 존재한다.' 라는 것. 
		adj[u].push_back(make_pair(w, v)); 
	}
	
	pq.push(make_pair(0, K)); // 첫 시작 지점의 거리값을 0으로 두고 시작 
	dist[K] = 0; // 자기 자신으로의 거리 0 
	
	// 위에서 시작 지점을 push 해놓아서 아래의 로직을 돌리면 갈 수 있는 곳들은 다 가는 것. 
	while(pq.size()){
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if(dist[here] != here_dist) // for문 안에서 dist[here]가 계속해서 업데이트 되는데, 가장 최신으로 업데이트된것만 사용하는 것. 
			continue;
		
		for(pair<int, int> there : adj[here]){ // 현재 지점에서 갈 수 있는 곳들 돌리기. 
			int _dist = there.first;
			int _there = there.second;
			
			if(dist[_there] > dist[here] + _dist){ // 새로운 거리가 더 짧은 경우 => 새로운 최단 거리 
				dist[_there] = dist[here] + _dist;
				pq.push(make_pair(dist[_there], _there)); // 새롭게 최단거리로 업데이트 된 곳에서 계속해서 나아가도록 하는 것. 
			}	
		}	
	}
	for(int i = 1; i <= V; i++){
		if(dist[i] == INF) // 새롭게 업데이트가 안된 경우 
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
	return 0;
}

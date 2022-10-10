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
	fill(dist, dist + 20001, INF); // ó���� ���Ѵ�� �����ϰ� �ִܰŸ� ����ؼ� ������Ʈ 
	for(int i = 0; i < E; i++){
		cin >> u >> v >> w; // 'u���� v�� ���� ����ġ w�� ������ �����Ѵ�.' ��� ��. 
		adj[u].push_back(make_pair(w, v)); 
	}
	
	pq.push(make_pair(0, K)); // ù ���� ������ �Ÿ����� 0���� �ΰ� ���� 
	dist[K] = 0; // �ڱ� �ڽ������� �Ÿ� 0 
	
	// ������ ���� ������ push �س��Ƽ� �Ʒ��� ������ ������ �� �� �ִ� ������ �� ���� ��. 
	while(pq.size()){
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if(dist[here] != here_dist) // for�� �ȿ��� dist[here]�� ����ؼ� ������Ʈ �Ǵµ�, ���� �ֽ����� ������Ʈ�Ȱ͸� ����ϴ� ��. 
			continue;
		
		for(pair<int, int> there : adj[here]){ // ���� �������� �� �� �ִ� ���� ������. 
			int _dist = there.first;
			int _there = there.second;
			
			if(dist[_there] > dist[here] + _dist){ // ���ο� �Ÿ��� �� ª�� ��� => ���ο� �ִ� �Ÿ� 
				dist[_there] = dist[here] + _dist;
				pq.push(make_pair(dist[_there], _there)); // ���Ӱ� �ִܰŸ��� ������Ʈ �� ������ ����ؼ� ���ư����� �ϴ� ��. 
			}	
		}	
	}
	for(int i = 1; i <= V; i++){
		if(dist[i] == INF) // ���Ӱ� ������Ʈ�� �ȵ� ��� 
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
	return 0;
}

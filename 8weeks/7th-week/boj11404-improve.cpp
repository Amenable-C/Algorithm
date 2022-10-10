#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, c, dist[104][104];
const int INF = 987654321;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	
	fill(&dist[0][0], &dist[0][0] + 104 * 104, INF);
	
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		a--; b--;
		dist[a][b] = dist[a][b] ? min(dist[a][b], c) : c; // 같은 경로를 가는 다른 버스가 존재할 경우 비용이 더 작은 것을 선택 
	}
	
	for(int k = 0; k < n; k++){ // 중간 도시들을 체크하는 거. 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j)
				cout << "0 ";
			else
				if(dist[i][j] == INF)
					cout << "0 ";
				else
					cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

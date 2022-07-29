#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int n, m, a[max_n][max_n], visited[max_n][max_n], y, x, sy, sx, ey, ex;

int main(){
	cin >> n >> m;
	cin >> sx >> sy;
	cin >> ex >> ey;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];	
	
	queue<pair<int, int>> q;
	visited[sx][sy] = 1;
	q.push({sx, sy});
	while(q.size()){
		tie(x, y) = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == 0)
				continue;
			
			if(visited[nx][ny]) continue;
			
			visited[nx][ny] = visited[x][y] + 1;
			q.push({nx, ny});
		}	
	}
	
	cout << "최단거리 : " << visited[ex][ey] << "\n";
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << visited[i][j] << ' ';
		cout << "\n";
	}
	return 0;
}

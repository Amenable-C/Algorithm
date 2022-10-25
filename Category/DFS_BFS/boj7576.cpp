#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string.h>

#define MAX 1004
using namespace std;

int n, m, a[MAX][MAX], cnt, ret, vis_tmp[MAX][MAX], visited[MAX][MAX], y, x, _y, _x;
vector<pair<int, int>> v;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
// 계속해서 bfs로 가면서 visited[]가 가장 큰 값을 구하면 됨. 
void check(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(vis_tmp[i][j] > 0 && vis_tmp[i][j] < visited[i][j])
				visited[i][j] = vis_tmp[i][j];
		}
	}
}

int all_clear(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(visited[i][j] == 987654321 && a[i][j] != -1)
				return 0;			
		}
	}
	return 1;
}

int max_day(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] != -1)
				ret = max(ret, visited[i][j]);
		}
	}
	return ret;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n;
	fill(&visited[0][0], &visited[n][m], 987654321);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 1){
				v.push_back({i, j});
				visited[i][j] = 1;
			}
		}
	}
	
	
	
	for(int i = 0; i < v.size(); i++){
		memset(vis_tmp, 0, sizeof(vis_tmp));
		
		tie(_y, _x) = v[i];
		queue<pair<int, int>> q;
		q.push({_y, _x});
		vis_tmp[_y][_x] = 1;
		while(q.size()){
			tie(y, x) = q.front();
			q.pop();
			for(int i = 0; i < 4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny < 0 || ny >= n || nx < 0 || nx >= m || vis_tmp[ny][nx] || a[ny][nx] == -1 || a[ny][nx] == 1)
					continue;
				vis_tmp[ny][nx] = vis_tmp[y][x] + 1;
				q.push({ny, nx});
			}
		}
		check();
	}
	
	// 안 익은게 있는지 체크
	if(!all_clear()){
		cout << -1;
		return 0;
	}
	
	// 가장 오래 걸린 곳 체크(거기에서 -1 해주기) 
	cout << max_day() - 1;
	return 0;	
}

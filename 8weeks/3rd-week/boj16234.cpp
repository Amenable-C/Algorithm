#include <bits/stdc++.h>
using namespace std;

int visited[54][54], a[54][54], n, l, r, cnt, sum;
vector<pair<int, int>> v;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, vector<pair<int, int>> &v){
	for(int i = 0 ; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx])
			continue;
			
		if(abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r){
			v.push_back({ny, nx});
			visited[ny][nx] = 1;
			sum += a[ny][nx];
			dfs(ny, nx, v);
		}
	}
}


int main(){
	cin >> n >> l >> r;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	
	while(true){
		bool flag = 0;
		memset(visited, 0, sizeof(visited));
//		fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(!visited[i][j]){
					
					v.clear();
					visited[i][j] = 1;
					v.push_back({i, j});
					sum = a[i][j]; // 여기서 초기화도 같이 진행 
					dfs(i, j, v);
					
					if(v.size() == 1)
						continue;
						
					for(pair<int, int> b : v){
						a[b.first][b.second] = sum / v.size();
						flag = 1;
					} 
				}
			}
		}
		
		
		
		if(!flag)
			break;
		cnt++;
	}
	
	cout << cnt;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;

int n, m, a[10][10], ret = 987654321;
vector<pair<int, int>> v;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};


vector<pair<int, int>> goCCTV(int here, int dir){
	int y = v[here].first;
	int x = v[here].second;
	vector<pair<int, int>> _change;
	
	if(a[y][x] == 1){
		while(true){		
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if(ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6){
				if(a[ny][nx] == 0){ // 뚫려있는 경우 
					a[ny][nx] = 8;
					_change.push_back({ny, nx});
				}
				// CCTV는 CCTV를 통과할 수 있으므로 if안에 다 적으면 안됨. 
				y = ny;
				x = nx;	
			}
			else
				break; 
		}	
	}
	else if(a[y][x] == 2){
		for(int i = 0; i <= 2; i+=2){ // 2방향으로 가는것 고려 
			int _y = y;
			int _x = x;
			while(true){
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];
				if(ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6){
					if(a[ny][nx] == 0){ 
						a[ny][nx] = 8;
						_change.push_back({ny, nx});
					}
					_y = ny;
					_x = nx;
				}
				else
					break; 
			}
		}
	}
	else if(a[y][x] == 3){
		for(int i = 0; i < 2; i++){ 
			int _y = y;
			int _x = x;
			while(true){
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];
				if(ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6){
					if(a[ny][nx] == 0){ 
						a[ny][nx] = 8;
						_change.push_back({ny, nx});
					}
					_y = ny;
					_x = nx;	
				}
				else
					break; 
			}
		}
	}
	else if(a[y][x] == 4){
		for(int i = 0; i < 3; i++){ 
			int _y = y;
			int _x = x;
			while(true){
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];
				if(ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6){
					if(a[ny][nx] == 0){ 
						a[ny][nx] = 8;
						_change.push_back({ny, nx});
					}
					_y = ny;
					_x = nx;	
				}
				else
					break; 
			}
		}
		
	}
	else if(a[y][x] == 5){
		for(int i = 0; i < 4; i++){ 
			int _y = y;
			int _x = x;
			while(true){
				int ny = _y + dy[(dir+i) % 4];
				int nx = _x + dx[(dir+i) % 4];
				if(ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6){
					if(a[ny][nx] == 0){ 
						a[ny][nx] = 8;
						_change.push_back({ny, nx});
					}
					_y = ny;
					_x = nx;	
				}
				else
					break; 
			}
		}
	}
	return _change;
}

void dfs(int here){
	if(here == v.size()){ // CCTV 탐색이 끝난 후 // 0을 카운트해서 ret 업데이트 
		int cnt = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] == 0){
					cnt++;
				}
			}
		}
		
		ret = min(ret, cnt);
		return;
	}
	
	for(int k = 0; k < 4; k++){
		vector<pair<int, int>> _change = goCCTV(here, k); // 카메라 번호 + 방향 
		dfs(here + 1);
		for(auto b : _change){
			a[b.first][b.second] = 0;
		}	
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];	
			if(a[i][j] != 0 && a[i][j] != 6){
				v.push_back({i, j});
			}
		}
	}
	
	dfs(0);
	cout << ret;
	
	return 0;
}

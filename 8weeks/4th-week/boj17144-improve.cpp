#include<bits/stdc++.h>
using namespace std;

int a[54][54], n, m, t, ret, temp[54][54];
vector<pair<int, int>> v1, v2;

// 시계방향, 반시계 방향 
int dy1[] = {0, -1, 0, 1};
int dx1[] = {1, 0, -1, 0};
int dy2[] = {0, 1, 0, -1};
int dx2[] = {1, 0, -1, 0};

void mise_go(int dy[], int dx[]){
	fill(&temp[0][0], &temp[0][0] + 54 * 54, 0);
	queue<pair<int, int>> q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] != -1 && a[i][j]){ // 미세먼지가 있는 지역 = 미세 먼지를 확산 시킬 지역 
				q.push({i, j});	
			}
		}
	}
	
	while(q.size()){
		int y, x;
		tie(y, x) = q.front();
		q.pop();
		
		int spread = a[y][x] / 5;
		
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == -1)
				continue;
			temp[ny][nx] += spread; // 확산 값을 더해주면서 진행을 하면 그 값이 다른 동작에 영향을 끼치므로 따로하기! 
			a[y][x] -= spread;
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			a[i][j] += temp[i][j];	
		}
		
	}
}



vector<pair<int, int>> chung(int sy, int sx, int dy[], int dx[]){
	vector<pair<int, int>> v;
	int cnt = 0;
	int y = sy;
	int x = sx;
	while(true){
		int ny = y + dy[cnt];
		int nx = x + dx[cnt];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m){
			cnt++;
			ny = y + dy[cnt];
			nx = x + dx[cnt];	
		}
		if(ny == sy && nx == sx)
			break;
		y = ny;
		x = nx;
		v.push_back({ny, nx});
	}
	return v; // 공기 청정기가 작동하는 길을 vec에 담아서 줌. 
}

void go(vector<pair<int, int>> &v){
	for(int i = v.size() - 1; i > 0; i--){
		a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
	}
	a[v[0].first][v[0].second] = 0; // 공기청정기로부터 바로 나오는 것.  
}


int main(){
	cin >> n >> m >>t;
	bool flag = 1;
	
	// 1. 입력 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == -1){
				if(flag){ // 위쪽 공기 청정기 // 반시계 방향 // 일반적인 좌표축과 다르므로 dy1, dx1이 맞음 
					v1 = chung(i, j, dy1, dx1);
					flag = false;	
				}
				else{ // 아래쪽 공기 청정기 // 시계 방향 
					v2 = chung(i, j, dy2, dx2);
				}
				
			}
		}
	}
	
	// 2. 확산 
	while(t--){
		mise_go(dy1, dx1);
		go(v1);
		go(v2);
	}
	
	// 3. 남아있는 미세먼지 체크 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] != -1)
				ret += a[i][j];
		}
	}
	
	cout << ret;
	return 0;
}

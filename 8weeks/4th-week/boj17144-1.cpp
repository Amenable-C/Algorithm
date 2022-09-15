#include<bits/stdc++.h>
using namespace std;

int r, c, t, a[54][54], temp[54][54], ret;
bool flag;
int dy1[] = {0, -1, 0, 1};
int dx1[] = {1, 0, -1, 0};
int dy2[] = {0, 1, 0, -1};
int dx2[] = {1, 0, -1, 0};
vector<pair<int, int>> v1, v2;

vector<pair<int, int>> chung(int sy, int sx, int dy[], int dx[]){
	vector<pair<int, int>> v;
	int y = sy;
	int x = sx;
	int d = 0;
	
	while(true){
		int ny = y + dy[d];
		int nx = x + dx[d];
		
		if(ny < 0 || ny >= r || nx < 0 || nx >= c){
			d++;
			continue;
		}
	
		
		if(ny == sy && nx == sx){
			break;
		}
		v.push_back({ny, nx});
		y = ny;
		x = nx;
		// 4방향으로만 확산이 되는 케이스면 이렇게 안해도 되는데 쭉쭉 가는거라서 y, x를 항상 업데이트 
	}
	return v;
}

void mise_go(){
	fill(&temp[0][0], &temp[0][0] + 54 * 54, 0);
	queue<pair<int, int>> q;
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(a[i][j] != -1 && a[i][j]){
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
			int ny = y + dy1[i];
			int nx = x + dx1[i];
			
			if(ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == -1){
				continue;	
			}
			
			a[y][x] -= spread;
			temp[ny][nx] += spread;
		}
		
	}
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			a[i][j] += temp[i][j];
		}	
	}
	
}

void chung_clean(vector<pair<int, int>> &vec){
	for(int i = vec.size() - 1; i > 0; i--){
		a[vec[i].first][vec[i].second] = a[vec[i - 1].first][vec[i - 1].second];	
	}
	a[vec[0].first][vec[0].second] = 0;
}


int main(){
	cin >> r >> c >> t;
	
	// 1. 입력 
	flag = 1;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> a[i][j];
			if(a[i][j] == -1){
				if(flag){
					v1 = chung(i, j, dy1, dx1); 
					flag = false;	
				}
				else{
					v2 = chung(i, j, dy2, dx2);
				}			
			}	
		}
	}
	
	// 2. 확산 & 공기 청정
	while(t--){
		mise_go();
		chung_clean(v1);
		chung_clean(v2);
	}
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(a[i][j] != -1){
				ret += a[i][j];
			}
		}
	}
	
	cout << ret;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n, m, fire[1004][1004], ji[1004][1004], y, x, ji_y, ji_x, ret = 987654321;
char a[1004][1004];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;

void bfs_f(int y, int x){
	queue<pair<int, int>> q;
	q.push({y, x});
	fire[y][x] = 1;
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 1 || ny >= n + 1 || nx < 1 || nx >= m + 1 || a[ny][nx] == '#')
				continue;
				
			if(fire[ny][nx] != 0 && fire[ny][nx] <= fire[y][x] + 1)
				continue;
				
			fire[ny][nx] = fire[y][x] + 1;
			q.push({ny, nx});
		}
	}
	return;
}

void bfs_ji(int y, int x){
	queue<pair<int, int>> q;
	q.push({y, x});
	ji[y][x] = 1;
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		if(y == 1 || y == n || x == 1 || x == m){
			if(fire[y][x] > ji[y][x])
				ret = min(ret, ji[y][x]);
			if(fire[y][x] == 0){
				ret = min(ret, ji[y][x]);
			}
		}
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 1 || ny >= n + 1 || nx < 1 || nx >= m + 1 || a[ny][nx] == '#' || ji[ny][nx])
				continue;
				
			ji[ny][nx] = ji[y][x] + 1;
			q.push({ny, nx});

		}
	}
	return;
}

int main(){
	cin >> n >> m;
	fill(&a[0][0], &a[n + 2][m + 2], '0');
	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < m + 1; j++){
			cin >> a[i][j];
			if(a[i][j] == 'F'){
				fire[i][j] = 1;
				v.push_back({i, j});	
			}
			else if(a[i][j] == 'J'){
				ji_y = i;
				ji_x = j;	
			}
		}
	}
	
	for(pair<int, int> i : v){
		bfs_f(i.first, i.second);
	}
	
	bfs_ji(ji_y, ji_x);
	if(ret == 987654321){
		cout << "IMPOSSIBLE";
	}
	else{
		cout << ret;
	}
	return 0;
}

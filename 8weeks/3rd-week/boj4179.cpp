#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
char a[1004][1004];
int r, c;
int fire[1004][1004], person[1004][1004];
queue<pair<int, int>> q;
int y, x;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int sy, sx;
int ret;

int main(){
	cin >> r >> c;	
	
	fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INF);
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> a[i][j];
			
			if(a[i][j] == 'F'){
				fire[i][j] = 1;
				q.push({i, j});
			}
			if(a[i][j] == 'J'){
				person[i][j] = 1;
				sy = i;
				sx = j;
			}
		}
	}
	
	
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= r || nx >= c) // 범위를 벗어난 경우 
				continue;
				
			if(fire[ny][nx] != INF || a[ny][nx] == '#') // 방문을 했거나, 벽인 경우 
				continue;	
			
			fire[ny][nx] = fire[y][x] + 1;
			q.push({ny, nx}); 
		}
	}
	
	q.push({sy, sx});
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		
		if(y == 0 || y == r - 1 || x == 0 || x == c - 1){
			ret = person[y][x];
			break;	
		}
		
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= r || nx >= c) // 범위를 벗어난 경우 
				continue;
				
			if(person[ny][nx] || a[ny][nx] == '#') // 이미 방문한 경우, 벽인 경우 
				continue;
		
			if(fire[ny][nx] <= person[y][x] + 1) // 불보다 느린경우 
				continue;
				
			person[ny][nx] = person[y][x] + 1;
			q.push({ny, nx});
		}		
	}
	
	if(ret != 0)
		cout << ret;
	else
		cout << "IMPOSSIBLE";
	
	return 0;
}

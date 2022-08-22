#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
char a[1004][1004];
int n, m, sx, sy, ret, y, x;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int fire_check[1004][1004], person_check[1004][1004];

bool in(int a, int b){
	return 0 <= a && a < n && 0 <= b && b < m;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	queue<pair<int, int>> q;
	
	cin >> n >> m;
//	memset(fire_check, INF, sizeof(fire_check));
	fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 'F'){
				fire_check[i][j] = 1;
				q.push({i, j}); // 여러개가 될 수 있음.  
			}else if(a[i][j] == 'J'){
				sy = i;
				sx = j;
			}
		}	
	}
	
	// 각 지점에서의 불의 최단시간 update 
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(!in(ny, nx))
				continue;
			
			if(fire_check[ny][nx] != INF || a[ny][nx] == '#')
				continue;
				
			fire_check[ny][nx] = fire_check[y][x] + 1; // 최단 시간을 구하기 위한 BFS 
			q.push({ny, nx}); // 계속해서 불이 번져나가는거. 
		
		}
	}
	// 여기 나오는 순간 queue가 없어짐 
	
	person_check[sy][sx] = 1;
	q.push({sy, sx});
	while(q.size()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		if(x == m - 1 || y == n - 1 || x == 0 || y == 0){
			ret = person_check[y][x]; // 최단거리로 도착한 경우 
			break;
		} 
		
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(!in(ny, nx))
				continue;
			if(person_check[ny][nx] || a[ny][nx] == '#')
				continue;
			
			if(fire_check[ny][nx] <= person_check[y][x] + 1) // 불이 이미 방문했다고 하더라도 사람이 가는거는 따로 카운트 하고 비교 
				continue;
			
			person_check[ny][nx] = person_check[y][x] + 1;
			q.push({ny, nx}); 
		}
	}
	
	if(ret != 0)
		cout << ret;
	else
		cout << "IMPOSSIBLE";
}

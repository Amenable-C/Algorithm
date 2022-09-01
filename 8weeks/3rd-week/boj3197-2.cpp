#include<bits/stdc++.h>
using namespace std;

int r, c, day, y, x, swanY, swanX;
char a[1501][1501];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
queue<pair<int, int>> swanQ, swanTQ, waterQ, waterTQ;
int visited[1501][1501], visited_swan[1501][1501];
string s;

void Qclear(queue<pair<int, int>> &q){
	queue<pair<int, int>> empty;
	swap(q, empty);
}

bool swan_move(){
	while(swanQ.size()){
		tie(y, x) = swanQ.front();
		swanQ.pop();
		
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited_swan[ny][nx])
				continue;
				
			visited_swan[ny][nx] = 1;
				
			if(a[ny][nx] == '.')
				swanQ.push({ny, nx});
			else if(a[ny][nx] == 'X')
				swanTQ.push({ny, nx});
			else if(a[ny][nx] == 'L')
				return true;
		}
	}
	return false;
}

void water_melt(){
	while(waterQ.size()){
		tie(y, x) = waterQ.front();
		waterQ.pop();
		
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx])
				continue;
				
			if(a[ny][nx] == 'X'){
				visited[ny][nx] = 1;
				waterTQ.push({ny, nx});
				a[ny][nx] = '.';	
			}
		}
	}
}


int main(){
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		cin >> s;
		for(int j = 0; j < c; j++){
			a[i][j] = s[j];
			
			if(a[i][j] == 'L'){
				swanY = i;
				swanX = j;
			}
			
			if(a[i][j] == '.' || a[i][j] == 'L'){
				visited[i][j] = 1;
				waterQ.push({i, j});
			}
		}
	}
	
	swanQ.push({swanY, swanX});
	visited_swan[swanY][swanX] = 1;
	
	while(true){
		if(swan_move())
			break;
			
		water_melt();
		waterQ = waterTQ;
		swanQ = swanTQ;
		Qclear(waterTQ);
		Qclear(swanTQ);
		day++;
	}
	
	cout << day;
	return 0;
}

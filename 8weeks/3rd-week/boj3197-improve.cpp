#include <bits/stdc++.h>
using namespace std;
const int max_n = 1501;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int visited_swan[max_n][max_n], visited[max_n][max_n], R, C, day, swanY, swanX, y, x;
char a[max_n][max_n];
queue<pair<int, int>> waterQ, water_tempQ, swanQ, swan_tempQ;
string s;

void Qclear(queue<pair<int, int>> &q){
	queue<pair<int, int>> empty;
	swap(q, empty);	
}

void water_melting(){
	while(waterQ.size()){ // 맨 처음턴에는 모든 '.'을 다 담아놓아서 그걸로 작동하고, 두번째부터는 water_tempQ인 테두리에서만 잘 작동. 
		tie(y, x) = waterQ.front();
		waterQ.pop();
		
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx])
				continue;
			
			if(a[ny][nx] == 'X'){
				visited[ny][nx] = 1;
				water_tempQ.push({ny, nx}); // waterQ가 아닌 water_tempQ에 담기는 거라서 계속해서 진행하는거 아님 // 그 전에꺼를 기준으로 한칸씩만 나아감 // 이거를 waterQ로 대체하면 다음턴에 또 작동가능 
				a[ny][nx] = '.';	
				
			}
			
		}
	
	}
}


bool move_swan(){
	while(swanQ.size()){
		tie(y, x) = swanQ.front();
		swanQ.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited_swan[ny][nx])
				continue;
			
			visited_swan[ny][nx] = 1;
			
			if(a[ny][nx] == '.') // 물이라서 계속 지나갈 수 있을때 
				swanQ.push({ny, nx});
			else if(a[ny][nx] == 'X') // 나중에 swan_tempQ를 swanQ라고 해서, 그걸로 다시 진행할 것. 
				swan_tempQ.push({ny, nx});
			else if(a[ny][nx] == 'L') // 백조끼리 만났을 때 
				return true;
		}
	}
	return false; 
}

int main(){
	cin >> R >> C;
	
	for(int i = 0; i < R; i++){
		cin >> s;
		for(int j = 0; j < C; j++){
			a[i][j] = s[j];
			if(a[i][j] == 'L'){ // 마지막껄로 정의가 되는데 그렇게 되어도 상관없음. 어짜피 (swanY, swanX)로부터 L을찾을거라서 
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
		if(move_swan()) // 만날 수 있는지 확인하는거 
			break;
		water_melting(); // 한번 녹이기 
		waterQ = water_tempQ;
		swanQ = swan_tempQ;
		Qclear(water_tempQ);
		Qclear(swan_tempQ);
		day++; 
	}
	cout << day;
	
	return 0;
	
}

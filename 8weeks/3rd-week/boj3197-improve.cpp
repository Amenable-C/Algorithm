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
	while(waterQ.size()){ // �� ó���Ͽ��� ��� '.'�� �� ��Ƴ��Ƽ� �װɷ� �۵��ϰ�, �ι�°���ʹ� water_tempQ�� �׵θ������� �� �۵�. 
		tie(y, x) = waterQ.front();
		waterQ.pop();
		
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx])
				continue;
			
			if(a[ny][nx] == 'X'){
				visited[ny][nx] = 1;
				water_tempQ.push({ny, nx}); // waterQ�� �ƴ� water_tempQ�� ���� �Ŷ� ����ؼ� �����ϴ°� �ƴ� // �� �������� �������� ��ĭ���� ���ư� // �̰Ÿ� waterQ�� ��ü�ϸ� �����Ͽ� �� �۵����� 
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
			
			if(a[ny][nx] == '.') // ���̶� ��� ������ �� ������ 
				swanQ.push({ny, nx});
			else if(a[ny][nx] == 'X') // ���߿� swan_tempQ�� swanQ��� �ؼ�, �װɷ� �ٽ� ������ ��. 
				swan_tempQ.push({ny, nx});
			else if(a[ny][nx] == 'L') // �������� ������ �� 
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
			if(a[i][j] == 'L'){ // ���������� ���ǰ� �Ǵµ� �׷��� �Ǿ �������. ��¥�� (swanY, swanX)�κ��� L��ã���Ŷ� 
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
		if(move_swan()) // ���� �� �ִ��� Ȯ���ϴ°� 
			break;
		water_melting(); // �ѹ� ���̱� 
		waterQ = water_tempQ;
		swanQ = swan_tempQ;
		Qclear(water_tempQ);
		Qclear(swan_tempQ);
		day++; 
	}
	cout << day;
	
	return 0;
	
}

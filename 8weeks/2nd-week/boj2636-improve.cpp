#include <bits/stdc++.h>
using namespace std;

int a[104][104], visited[104][104];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, m, cnt, cnt2;

vector<pair<int, int>> v;

void go(int y, int x){
	visited[y][x] = 1;
	if(a[y][x] == 1){ // 치즈인 경우 
		v.push_back({y, x});
		return;	
	}
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) // visited를 이렇게 적어야지 겉에 한 면만 처리 가능 
			continue;
		
		go(ny, nx);
	}
	
	return;
}

int main(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}

	while(true){
		cnt2 = 0;
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		v.clear();
		
		go(0, 0);
		
		for(pair<int, int> b : v){
			cnt2++;
			a[b.first][b.second] = 0;	
		}
		
		bool flag = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] != 0)
					flag = 1;
			}
		}
		
		cnt++;
		if(!flag) // 치즈가 없는 경우 
			break;
		
		 
	}
	
	cout << cnt << "\n" << cnt2 << "\n"; 
}

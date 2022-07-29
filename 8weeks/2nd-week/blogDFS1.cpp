#include <bits/stdc++.h>
using namespace std;

int n, m, ret, nx, ny;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int a[104][104];
bool visited[104][104];

void dfs(int x, int y){
	visited[x][y] = 1;
	for(int i = 0; i < 4; i++){
		nx = x + dx[i];
		ny = y + dy[i];	
		if(nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		if(a[nx][ny] == 1 && !visited[nx][ny]){
			dfs(nx, ny);
		}
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
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 1 && !visited[i][j]){ // 확산이 안된 경우 
				ret++;
				dfs(i, j); // 확산 
			}
		}
	}
	
	cout << ret;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n, m, ret = 987654321, visited[104][104];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
char a[104][104];

void go(int y, int x, int cnt){
	if(y == n - 1 && x == m - 1){
		
		ret = min(ret, cnt);
	}
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || a[ny][nx] == '0')
			continue;
		visited[y][x] = 1;
		go(ny, nx, cnt + 1);
		visited[y][x] = 0;
	}
	return;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	
	go(0, 0, 1);
	cout << ret;
	return 0;
}

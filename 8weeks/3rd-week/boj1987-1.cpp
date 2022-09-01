#include <bits/stdc++.h>
using namespace std;
int r, c, y, n, ret, cnt, visited[30];
char a[21][21];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void go(int y, int x, int cnt){
	ret = max(ret, cnt);
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny >= r || nx >= c)
			continue;
		
		if(visited[a[ny][nx] - 'A']	== 0){
			visited[a[ny][nx] - 'A'] = 1;
			go(ny, nx, cnt + 1);
			visited[a[ny][nx] - 'A'] = 0;
		}
	}
}

int main(){
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> a[i][j];
		}
	}
	
	visited[(int)a[0][0] - 'A'] = 1;
	go(0, 0, 1);
	
	cout << ret;
	return 0;
}

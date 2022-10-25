#include<iostream>
#include<algorithm>
using namespace std;

int n, m, a[24][24], ret;
char c;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void go(int y, int x, int cnt, int bm){
	ret = max(ret, cnt);
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m)
			continue;	
		if(bm & (1 << a[ny][nx]))
			continue;
		go(ny, nx, cnt + 1, bm | (1 << a[ny][nx]));
	}
	return;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> c;
			a[i][j] = c - 'A';
		}
	}
	
	go(0, 0, 1, (1 << a[0][0]));
	
	cout << ret;
	return 0;
}

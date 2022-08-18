#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int r, c, k, visited[10][10];
char a[10][10];
string s;

int go(int y, int x){
	if(y == 0 && x == c - 1){
		if(k == visited[y][x])
			return 1;
		return 0;
	}
	
	int ret = 0;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || a[ny][nx] == 'T')
			continue;
		
		visited[ny][nx] = visited[y][x] + 1;
		ret += go(ny, nx);
		visited[ny][nx] = 0;
	}
	
	return ret;
	
}

int main(){
	cin >> r >> c >> k;
	
	for(int i = 0; i < r; i++){
		cin >> s;
		for(int j = 0; j < c; j++){
			a[i][j] = s[j];	
		}
	}
	
	visited[r-1][0] = 1;
	cout << go(r-1, 0);
	
}

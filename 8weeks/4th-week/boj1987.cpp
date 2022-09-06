#include<bits/stdc++.h>
using namespace std;

char a[25][25];
int visited[25][25], check[30];
int r, c, ret;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
string s;

void go(int y, int x, int cnt){
	ret = max(ret, cnt);
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny >= r || nx >= c || check[a[ny][nx] - 'A'])
			continue;
			
		check[a[ny][nx] - 'A'] = 1;
		go(ny, nx, cnt + 1);
		check[a[ny][nx] - 'A'] = 0;
		
	}
}


int main(){
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		cin >> s;
		for(int j = 0; j < c; j++){
			a[i][j] = s[j];	
		}
	}
	
	check[a[0][0] - 'A'] = 1;
	
	go(0, 0, 1);
	cout << ret;
}

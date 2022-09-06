#include <bits/stdc++.h>
using namespace std;
int r, c, ret;
char a[30][30];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void go(int y, int x, int num, int cnt){
	ret = max(cnt, ret);
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny >= r || nx >= c)
			continue;
		
		int _next = (1 << (a[ny][nx] - 'A'));
		if((num & _next) == 0){
			go(ny, nx, num | _next, cnt + 1);	
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
	
	go(0, 0, (1 << a[0][0] - 'A'), 1);
	cout << ret;
	return 0;
}

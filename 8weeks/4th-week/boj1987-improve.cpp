#include<bits/stdc++.h>
using namespace std;
int r, c, ret, ny, nx;
char a[21][21];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void go(int y, int x, int num, int cnt){
	ret = max(ret, cnt);
	
	for(int i = 0; i < 4; i++){
		ny = y + dy[i];
		nx = x + dx[i];
		
		if(ny < 0 || ny >= r || nx < 0 || nx >= c)
			continue;
		
		int _next = (1 << (a[ny][nx] - 'A')); // 기존에 배열을 사용해서 알파벳을 표현한거를 비트마스킹으로 변경한거 
		if((num & _next) == 0)
			go(ny, nx, num | _next, cnt+1); // 기존값을 변경하는게 아니라 인자를 변경함 
	}
		
}

int main(){
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> a[i][j];
		}
	}
	
	go(0, 0, 1 << (a[0][0] - 'A'), 1);
	cout << ret;
	return 0;
}

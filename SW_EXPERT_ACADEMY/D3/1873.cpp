#include<bits/stdc++.h>
using namespace std;

int t, h, w, n, y, x, s_length;
char a[104][104];
pair<int, int> p;
string s;

// 순서 = ^ > v <
int dy[] = {-1, 0, 1, 0}; 
int dx[] = {0, 1, 0, -1};

map<char, int> mp; 

pair<int, int> go(int y, int x, int i){	
	int ny = y, nx = x;
	if(s[i] == 'S'){ // 슈팅하는 경우
		int dir = mp[a[y][x]];
		
		while(true){
			ny = ny + dy[dir];
			nx = nx + dx[dir];
			
			if(ny < 0 || ny >= h || nx < 0 || nx >= w){
				return {y, x};
			}
			
			if(a[ny][nx] == '*'){
				a[ny][nx] = '.';
				return {y, x};
			}
			else if(a[ny][nx] == '#'){
				return {y, x};
			}
		}	
	}
	else{ // 이동하는 경우 
		// 고개 돌리기
		if(s[i] == 'U'){
			a[y][x] = '^';
		}
		else if(s[i] == 'D'){
			a[y][x] = 'v';
		}
		else if(s[i] == 'L'){
			a[y][x] = '<';
		}
		else if(s[i] == 'R'){
			a[y][x] = '>';
		}
		
		int dir = mp[a[y][x]];
		ny = y + dy[dir];
		nx = x + dx[dir];
		
		// 갈 수 있으면 가고 아니면 멈춰있기 
		if(a[ny][nx] == '.'){
			a[ny][nx] = a[y][x];
			a[y][x] = '.';
			return {ny, nx};
		}
		
		return {y, x};
		
		
	}
		
}

int main(){
	mp['^'] = 0;
	mp['>'] = 1;
	mp['v'] = 2;
	mp['<'] = 3;
	cin >> t;
	for(int _t = 1; _t <= t; _t++){
		memset(a, 0, sizeof(a));
		cin >> h >> w;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> a[i][j];
				if(a[i][j] == '^' || a[i][j] == 'v' || a[i][j] == '<' || a[i][j] == '>'){
					p = {i, j}; // 처음 위치 기억하기. 
				}
			}
		}
		cin >> s_length;
		cin >> s;
		
		tie(y, x) = p;
		for(int i = 0; i < s.size(); i++){
			tie(y, x) = go(y, x, i);
		}
		
		cout << "#" << _t << " ";
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cout << a[i][j];
			}
			cout << "\n";
		}
		
	}
	return 0; 
}

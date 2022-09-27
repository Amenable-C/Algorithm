#include<bits/stdc++.h>
using namespace std;

int n, x, y, d, g;
int cnt, a[104][104];
vector<int> dragon_d[4][11];

const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};

void dragon_go(int x, int y, int d, int g){
	int _x = x;
	int _y = y;
	a[_x][_y] = 1;
	for(int i = 0; i <= g; i++){
		for(int dir : dragon_d[d][i]){
			_x += dx[dir];
			_y += dy[dir];
			a[_x][_y] = 1;
		}
	}
	return;
}

void make_dragon_direction(){
	for(int i = 0; i < 4; i++){
		dragon_d[i][0].push_back(i);
		dragon_d[i][1].push_back((i + 1) % 4);
		for(int j = 2; j <= 10; j++){
			int _n = dragon_d[i][j-1].size();
			for(int k = _n - 1; k >= 0; k--){
				dragon_d[i][j].push_back((dragon_d[i][j-1][k] + 1) % 4);
			}
			for(int k = 0; k < _n; k++){
				dragon_d[i][j].push_back(dragon_d[i][j - 1][k]);	
			}
		}
	}
	return;
}

int main(){
	cin >> n;
	
	make_dragon_direction();
	
	for(int i = 0; i < n; i++){
		cin >> x >> y >> d >> g;
		dragon_go(x, y, d, g);
	}
	
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			if(a[i][j] && a[i][j+1] && a[i+1][j] && a[i+1][j+1])
				cnt++;
		}
	}
	
	cout << cnt;
	return 0;
}

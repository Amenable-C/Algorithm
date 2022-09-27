#include<bits/stdc++.h>
using namespace std;

/*
<규칙>
방향을 찾아서 시작점을 기준으로 각 선을 그리면 됨 

0
1
2 1
2 3 2 1
2 3 0 3 2 3 2 1

('이전 배열의 역순 + 1' % 4) + (이전 배열 그대로)
*/

// 방향은 정해진게 아니라 문제에서 주는걸로 방향 만들기 
const int dy[] = {0, -1, 0 , 1};
const int dx[] = {1, 0, -1, 0};

vector<int> dragon[4][11];
int cnt, n, x, y, d, g, a[101][101];

void go(int x, int y, int d, int g){
	int _x = x;
	int _y = y;
	a[_x][_y] = 1; // 시작점 맵핑
	for(int i = 0; i <= g; i++){ // 
		for(int dir : dragon[d][i]){ // vector에 있는 방향들 모두 사용하는 것 // 그리고 계속해서 끝점을 이어나가는 것 
			_x += dx[dir];
			_y += dy[dir];
			a[_x][_y] = 1;	
		}
	}
	return;
}

// 4가지 방향을 기준으로 10세대까지 방향성을 정의
void makeDragon(){
	for(int i = 0; i < 4; i++){
		dragon[i][0].push_back(i);
		dragon[i][1].push_back((i + 1) % 4);
		for(int j = 2; j <= 10; j++){
			int _n = dragon[i][j - 1].size();
			for(int k = _n - 1; k >= 0; k--){
				dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4); // ('이전 배열의 역순 + 1' % 4)
			}
			for(int k = 0; k < _n; k++){
				dragon[i][j].push_back(dragon[i][j - 1][k]); // (이전 배열 그대로)
			}
		}
	}
	return;
}

int main(){
	cin >> n;
	makeDragon();
	
	for(int i = 0; i < n; i++){
		cin >> x >> y >> d >> g;
		go(x, y, d, g);	// 드래곤 커브 만들기 
	}
	
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			if(a[i][j] && a[i + 1][j] && a[i + 1][j + 1] && a[i][j + 1]) // 1x1인 정사각형의 네 꼭지점이 모두 드래곤 커브인거 찾기
				cnt++;
		}
	}
	
	cout << cnt;
	return 0;
}

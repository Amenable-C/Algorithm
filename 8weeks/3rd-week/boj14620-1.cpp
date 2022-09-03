#include<bits/stdc++.h>
using namespace std;

int n, m[20][20], v[20][20];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ret = 987654321;

bool check(int y, int x){
	if(v[y][x])
		return false;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= n || v[ny][nx])	
			return false;	
	}
	return true;
}

int setFlower(int y, int x){
	v[y][x] = 1;
	int s = m[y][x];
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		v[ny][nx] = 1;
		s += m[ny][nx];
	}
	return s;
}

void eraseFlower(int y, int x){
	v[y][x] = 0;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		v[ny][nx] = 0;
	}
}

void flower(int cnt, int sum){
	if(cnt == 3){
		ret = min(ret, sum);
		return;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(check(i, j)){
				flower(cnt + 1, sum	+ setFlower(i, j));
				eraseFlower(i, j);
			}
		}
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> m[i][j];
		}
	}
	
	flower(0, 0);
	cout << ret;
	return 0;
}

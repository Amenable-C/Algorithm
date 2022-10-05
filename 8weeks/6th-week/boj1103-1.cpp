#include<bits/stdc++.h>
using namespace std;

int n, m, d[54][54];
int b[54][54];
bool visited[54][54];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
string s;

bool in(int yy, int xx){
	return (0 <= yy && yy < n && 0 <= xx && xx < m);	
}

int go(int y, int x){
	if(!in(y, x) || b[y][x] == 'H'){
		return 0;
	}
	if(visited[y][x]){
		cout << -1;
		exit(0);	
	}
	
	int &ret = d[y][x];
	if(ret){
		return ret;
	}
	
	visited[y][x] = 1;
	int value = (int)b[y][x] - '0';
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i] * value;
		int nx = x + dx[i] * value;
		ret = max(ret, go(ny, nx) + 1);
	}
	visited[y][x] = 0;
	return ret;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			b[i][j] = s[j];
		}
	}
	
	cout << go(0, 0);
	return 0;
}

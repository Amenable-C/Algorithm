#include<bits/stdc++.h>
using namespace std;

int n, l, r, a[54][54], flag, visited[54][54], cnt;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;


void dfs(int y, int x){
	visited[y][x] = 1;
	v.push_back({y, x});
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
			continue;
			
		if(abs(a[y][x] - a[ny][nx]) < l || 	abs(a[y][x] - a[ny][nx]) > r)
			continue;
			
		flag++;
		dfs(ny, nx);
	}
	return;
}

void go(){
	int sum = 0;
	for(pair<int, int> i : v){
		sum += a[i.first][i.second];
	}
	
	sum /= v.size();
	
	for(pair<int, int> i : v){
		a[i.first][i.second] = sum;
	}
}


int main(){
	cin >> n >> l >> r;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	
	while(true){
		flag = 0;
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(visited[i][j] == 0){
					v.clear();
					dfs(i, j);
					go(); // v에 있는 것들 인구 이동 
				}
			}
		}
		
		if(flag == 0)
			break;
		else{
			cnt++;	
		}
	}
	cout << cnt;
	return 0;
}

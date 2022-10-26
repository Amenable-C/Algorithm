#include<bits/stdc++.h>
using namespace std;

int n, m, a[104][104], visited[104][104], ret, pre, cnt;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int dfs(int y, int x){
	visited[y][x] = 1;
	
	if(a[y][x] == 1){
		a[y][x] = 0;
		return 1;
	}
	
	int sum = 0;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || ny >= n + 2 || nx < 0 || nx >= m + 2 || visited[ny][nx])
			continue;
		
		sum += dfs(ny, nx);
	}
	return sum;
}


int main(){
	cin >> n >> m;
	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < m + 1; j++){
			cin >> a[i][j];
		}
	}
	
	while(true){
		memset(visited, 0, sizeof(visited));
		ret = dfs(0, 0);
		if(ret == 0){
			break;	
		}
		else{
			cnt++;
			pre = ret;	
		}
		
		
	}
	cout << cnt << "\n" << pre;
	return 0;
	
	
	
}

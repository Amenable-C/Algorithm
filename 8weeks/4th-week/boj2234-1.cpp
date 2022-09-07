#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0}; 

int visited[54][54], a[54][54], compSize[2504], n, m, mx, big, cnt;

int dfs(int y, int x, int cnt){
	if(visited[y][x])
		return 0;
		
	visited[y][x] = cnt;
	int ret = 1;
	
	for(int i = 0; i < 4; i++){
		if(!(a[y][x] & (1 << i))){
			int ny = y + dy[i];
			int nx = x + dx[i];
			ret += dfs(ny, nx, cnt);	
		}
	}
	return ret;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];	
		}
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j]){
				cnt++;
				compSize[cnt] = dfs(i, j, cnt);
				mx = max(mx, compSize[cnt]);	
			}
		}
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(i + 1 < m){
				int a = visited[i][j];
				int b = visited[i+1][j];
				if(a != b){
					big = max(big, compSize[a] + compSize[b]);
				}
			}
			if(j + 1 < n){
				int a = visited[i][j];
				int b = visited[i][j+1];
				if(a != b){
					big = max(big, compSize[a] + compSize[b]);
				}
			}
		}
	}
	
	cout << cnt << "\n" << mx << "\n" << big;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

const int max_n = 104;

int n, h, max_h, y, x, ny, nx, a[max_n][max_n], visited[max_n][max_n], ret, max_ret;

// ���̰� �޶����� ���� ������ ������ �ִ� ���� ���ϱ� 

void dfs(int y, int x, int dfs_h){
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++){
		ny = y + dy[i];
		nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;
			
		if(a[ny][nx] > dfs_h && !visited[ny][nx]){
			dfs(ny, nx, dfs_h);
		}
	}
	
	return;	
}


int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(a[i][j] > max_h)
				max_h = a[i][j];
		}
	}
	
	// min_h�� �������ϸ� �ð��ʰ��� ���? 
	for(int i = 0; i < max_h; i++){
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				if(a[j][k] > i && !visited[j][k]){
					dfs(j, k, i);
					ret++;
				}
			}
			
		}
		
		if(max_ret < ret)
			max_ret = ret;
		ret = 0;
	
	}
	
	cout << max_ret;
}

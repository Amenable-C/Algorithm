#include<bits/stdc++.h>
using namespace std;

int a[104][104], m, n, k, x_1, x_2, y_1, y_2;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

vector<int> ret;

int dfs(int y, int x){
	a[y][x] = 1;
	
	int _ret = 1;
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= m || nx >= n || a[ny][nx] == 1)
			continue;
		
		_ret += dfs(ny, nx);
	}
	
	return _ret;	
}

int main(){
	cin >> m >> n >> k;	
	
	for(int i = 0; i < k ;i ++){
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		for(int x = x_1; x < x_2; x++){
			for(int y = y_1; y < y_2; y++){
				a[y][x] = 1;
			}
		}
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] != 1){
				ret.push_back(dfs(i, j));	
			}
		}
	}
	
	sort(ret.begin(), ret.end());
	cout << ret.size() << "\n";
	for(int _ret : ret)
		cout << _ret << " ";
	
	return 0;
}

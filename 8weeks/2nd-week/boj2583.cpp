#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

const int max_n = 104;

int m, n, k, ret, a[max_n][max_n], visited[max_n][max_n], p1_x, p1_y, p2_x, p2_y, ny, nx; 
int num;



void dfs(int x, int y){
	ret++;
	visited[x][y] = 1;
	for(int i = 0; i < 4; i++){
		nx = x + dx[i];
		ny = y + dy[i];
		
		if(ny < 0 || nx < 0 || ny >= m || nx >= n)
			continue;
			
		if(a[nx][ny] == 0 && !visited[nx][ny])
			dfs(nx, ny);
	}
	return;	
}

int main(){
	cin >> m >> n >> k;
	
	for(int i = 0; i < k; i++){
		cin >> p1_x >> p1_y >> p2_x >> p2_y;
		for(int j = p1_y; j < p2_y; j++){
			for(int k = p1_x; k < p2_x; k++){
				a[k][j] = 1; // 막혀있다는 걸로 사용	
			}
		}
	}
	
	vector<int> v;
	int total = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 0 && !visited[i][j]){
				num++;
				dfs(i, j);
			}
			if(ret){
			v.push_back(ret);
		}
		ret = 0;
		}
		
	}
	
	cout << num << endl;
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < v.size(); i++){
		cout << v.at(i) << " ";
		
	}
}

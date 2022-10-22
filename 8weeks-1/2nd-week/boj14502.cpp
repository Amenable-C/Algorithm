#include<bits/stdc++.h>
using namespace std;

int n, m, a[10][10], ret, check[10][10], y, x;
vector<pair<int, int>> v;
queue<pair<int, int>> spread;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int go(){
	int cnt = 0;
	memset(check, 0, sizeof(check));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 2){ // 바이러스인 경우 
				check[i][j] == 1;
				spread.push({i, j});
				while(spread.size()){
					tie(y, x) = spread.front();
					spread.pop();
					for(int i = 0; i < 4; i++){
						int ny = y + dy[i];
						int nx = x + dx[i];
						
						if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 1 || check[ny][nx] == 1)
							continue;
						
						check[ny][nx] = 1;
						spread.push({ny, nx}); 
					}
				}
			}	
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(check[i][j] == 0 && a[i][j] != 1 && a[i][j] != 2){
				cnt++;
			}	
		}
	}
	return cnt;
}


int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 0)
				v.push_back({i, j});
		}
	}
	
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < i; j++){
			for(int k = 0; k < j; k++){
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1;
				ret = max(ret, go());
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0;
			}
		}
	}
	cout << ret;
	return 0;
}

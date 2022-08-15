#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, m, t, last, a[104][104];
bool vis[104][104];

vector<pair<int, int>> v;

void go(int y, int x){
	
	vis[y][x] = true;
	
	if(a[y][x] == 1){
		v.push_back({y, x});
		return;	
	}
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny >= n || nx >= m || vis[ny][nx])
			continue;
		
		go(ny, nx);
	}
	
	return;
}



int main(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	
	while(true){
		t++;
		last = 0;
		memset(vis, 0, sizeof(vis));
		v.clear();
		
		go(0, 0);
		
		for(pair<int, int> pi : v){
			last++;
			a[pi.first][pi.second] = 0;
		}
				
		bool cheese = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j]){
					cheese = true;
				}
			}
		}
		
		if(!cheese)
			break;
	}
	
	cout << t << "\n" << last;
		
}

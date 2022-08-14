#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int a[104][104];
bool vis[104][104]; 

int cheese, t, last;
int n, m;

int check(int y, int x){
	if(vis[y][x])
		return false;
	
	vis[y][x] = true;
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny >= n || nx >= m){
			continue;
		}
		
		if(a[ny][nx] == 0 && vis[ny][nx] == false){
			return true;
		}
	}
	return false;
	
}

int main(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j])
				cheese++;
		}
	}
	
	while(cheese){
		memset(vis, 0, sizeof(vis));
		last = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j]){
					if(check(i, j)){ 
						a[i][j] = 0;
						cheese--;
						last++;
					}
				}
			}
		}
		
		cout << endl;
		cout << endl;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		
		t++;
	}
	// 이렇게 하면 안쪽도 녹는거임. 
	
	cout << t << "\n";
	cout << last;
}

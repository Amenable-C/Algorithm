#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, m, a[10][10];
vector<pi> v;

bool vis[10][10];

void dfs(int y, int x){
	if(a[y][x] == 1 || vis[y][x])
		return;
		
	vis[y][x] = 1;
		
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;
		
		dfs(ny, nx);
	}
}

int solve(){
	memset(vis, 0, sizeof(vis));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 2)
				dfs(i, j);
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < m; j++){
			if(!vis[i][j] && a[i][j] == 0)
				ans++;
		}
	}
	return ans;
}

int main(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(!a[i][j])
				v.push_back(pi(i, j));
		}
	}
	
	assert(v.size() >= 3);
	
	int ans = 0;
	
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < i; j++){
			for(int k = 0; k < j; k++){ // 이렇게 for문을 만들면 빈 칸에 대하여 3개씩 벽을 만들 수 있음. 
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1; // 벽 3개 설정 
				ans = max(ans, solve()); // 최대크기 설정 
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0; // 설정한 벽 초기화 
			}
		}
	}
	
	cout << ans;
}


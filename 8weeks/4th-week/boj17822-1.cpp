#include<bits/stdc++.h>
using namespace std;


int n, m, t, a[54][54], x, d, k, visited[54][54], ret;
bool no_boom = 1;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void _rotate(int y, int dir, int k){
	vector<int> v;
	for(int i = 0; i < m; i++){
		v.push_back(a[y][i]);	
	}
	
	if(dir == 0){ // 시계 
		rotate(v.begin(), v.begin() + m - k, v.end());
	}
	else if(dir == 1){ // 반시계 
		rotate(v.begin(), v.begin() + k, v.end());
	}
	
	for(int i = 0; i < m; i++){
		a[y][i] = v[i];	
	}
	
	return;
}

void dfs(int y, int x){
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = (x + dx[i] + m) % m;
		
		if(ny < 0 || ny >= n)
			continue;
		
		if(visited[ny][nx])
			continue;
		
		if(a[y][x] == a[ny][nx]){
			visited[y][x] = visited[ny][nx] = 1;
			no_boom = 0;
			dfs(ny, nx); // 여기서 바로 해줘야 함!! 
		}
	}
}

bool find_adj(){
	no_boom = 1;
	memset(visited, 0, sizeof(visited)); 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 0 || visited[i][j] == 1)
				continue;
			dfs(i, j);
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(visited[i][j] == 1)
				a[i][j] = 0;
		}
	}
	return no_boom;
}

void set_average(){
	int sum = 0, cnt = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] != 0){
				sum += a[i][j];
				cnt++;	
			}
		}
	}
	
	double avg = (double) sum / (double) cnt;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 0)			
				continue;
				
			if((double)a[i][j] > avg){
				a[i][j]--;	
			}
			else if((double)a[i][j] < avg){
				a[i][j]++;
			}
		}
	}
	return;
}


int main(){
	cin >> n >> m >> t;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];	
		}
	}
	
	for(int i = 0; i < t; i++){
		cin >> x >> d >> k;
		for(int j = x - 1; j < n; j += x){
			_rotate(j, d, k);	
		}
		
		if(find_adj()){
			set_average(); 
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ret += a[i][j];	
		}
	}
	
	cout << ret;
	return 0;
}

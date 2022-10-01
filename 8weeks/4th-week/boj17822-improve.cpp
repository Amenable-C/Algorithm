#include<bits/stdc++.h>
using namespace std;

#define y abcd

int n, m, T, x, d, k, a[54][54], ret, visited[54][54], y;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool flag = 1;

void _rotate(int y, int dir, int k){ // y를 기준으로 회전 
	vector<int> v;
	for(int i = 0; i < m; i++){
		v.push_back(a[y][i]);	
	}
	
	if(dir == 1){ // 1인 경우 반시계, 0인 경우 시계 
		rotate(v.begin(), v.begin() + k, v.end()); // 왼쪽으로 이동 => 반시계
	}
	else
		rotate(v.begin(), v.begin() + m - k, v.end()); // 오른쪽으로 이동 => 시계 
	
	for(int i = 0; i < m; i++)
		a[y][i] = v[i];
	
	return; 
}

void dfs(int y, int x){
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = (x + dx[i] + m) % m; // -1방향도 있기 때문에 +m을 해주기 %m 하기! 
		if(ny < 0 || ny >= n) // 범위 고려. 
			continue;
		if(visited[ny][nx])
			continue;
		if(a[y][x] == a[ny][nx]){
			visited[y][x] = visited[ny][nx] = 1;
			flag = 0;
			dfs(ny, nx); // 터진 경우는 visited 가 1로 됨. 만약에 여기서 dfs를 안해주면 findAdj에서 continue로 넘어가는 문제 발생 
		}
	}
}

bool findAdj(){
	flag = 1;
	memset(visited, 0, sizeof(visited));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 0) // 그 전에 지운 경우 
				continue;
			if(visited[i][j]) // 이번 턴에 지운 경우 
				continue;
			dfs(i, j);	
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(visited[i][j]) // 지운 경우 0으로 만들기 // 바로 0으로 만들면 dfs가 제대로 동작하지 않음. 
				a[i][j] = 0;
		}
	}
	return flag; // 인접하면서 같은 수가 있는 경우는 dfs에서 flag가 0으로 바뀜 
}

void setAverage(){
	int sum = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 0)
				continue;
			sum += a[i][j];
			cnt++;
		}
	}
	
	double av = (double) sum / (double) cnt;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 0)
				continue;
			if((double)a[i][j] > av)
				a[i][j]--;
			else if((double)a[i][j] < av)
				a[i][j]++;
		}
	}
	return;
}

int main(){
	cin >> n >> m >> T; // n개의 원판, m개의 수, T번 회전 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < T; i++){
		cin >> x >> d >> k; // x의 배수인 원판을 d방향으로 k칸 회전 
		for(int j = x - 1; j < n; j += x){
			_rotate(j, d, k);	
		}
		if(findAdj())
			setAverage();
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ret += a[i][j];	
		}
	}
	
	cout << ret;
	return 0;
}

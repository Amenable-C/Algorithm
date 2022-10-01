#include<bits/stdc++.h>
using namespace std;

#define y abcd

int n, m, T, x, d, k, a[54][54], ret, visited[54][54], y;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool flag = 1;

void _rotate(int y, int dir, int k){ // y�� �������� ȸ�� 
	vector<int> v;
	for(int i = 0; i < m; i++){
		v.push_back(a[y][i]);	
	}
	
	if(dir == 1){ // 1�� ��� �ݽð�, 0�� ��� �ð� 
		rotate(v.begin(), v.begin() + k, v.end()); // �������� �̵� => �ݽð�
	}
	else
		rotate(v.begin(), v.begin() + m - k, v.end()); // ���������� �̵� => �ð� 
	
	for(int i = 0; i < m; i++)
		a[y][i] = v[i];
	
	return; 
}

void dfs(int y, int x){
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = (x + dx[i] + m) % m; // -1���⵵ �ֱ� ������ +m�� ���ֱ� %m �ϱ�! 
		if(ny < 0 || ny >= n) // ���� ���. 
			continue;
		if(visited[ny][nx])
			continue;
		if(a[y][x] == a[ny][nx]){
			visited[y][x] = visited[ny][nx] = 1;
			flag = 0;
			dfs(ny, nx); // ���� ���� visited �� 1�� ��. ���࿡ ���⼭ dfs�� �����ָ� findAdj���� continue�� �Ѿ�� ���� �߻� 
		}
	}
}

bool findAdj(){
	flag = 1;
	memset(visited, 0, sizeof(visited));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 0) // �� ���� ���� ��� 
				continue;
			if(visited[i][j]) // �̹� �Ͽ� ���� ��� 
				continue;
			dfs(i, j);	
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(visited[i][j]) // ���� ��� 0���� ����� // �ٷ� 0���� ����� dfs�� ����� �������� ����. 
				a[i][j] = 0;
		}
	}
	return flag; // �����ϸ鼭 ���� ���� �ִ� ���� dfs���� flag�� 0���� �ٲ� 
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
	cin >> n >> m >> T; // n���� ����, m���� ��, T�� ȸ�� 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < T; i++){
		cin >> x >> d >> k; // x�� ����� ������ d�������� kĭ ȸ�� 
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

#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int INF = 987654321;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int n, m, k, a[104][104], b[104][104], ret = INF, r, c, s, visited[104][104], dir, sy, sx, ey, ex;
vector<pair<int, int>> vv;
vector<int> v_idx;

struct A{
	int y, x, cnt;	
};

vector<A> v;

bool cmp(A &a, A &b){
	if(a.y == b.y) 
		return a.x < b.x;
	return a.y < b.y;	
}

void go(int y, int x, int first){
	if(!first && y == sy && x == sx)
		dir++;
	if(!first && y == sy && x == ex)
		dir++;
	if(!first && y == ey && x == ex)
		dir++;
	if(!first && y == ey && x == sx)
		dir++;
		
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	
	if(visited[ny][nx]) // 사각형으로 다 돌고나서 시작점과 만나면 break 
		return;
		
	visited[ny][nx] = 1;
	vv.push_back({ny, nx});
	go(ny, nx, 0);
	
	
}

void rotateAll(int y, int x, int cnt){
	for(int i = 1; i <= cnt; i++){ // 가운데를 기준으로 한 겹씩 돌리는거 
		sy = y - 1 * i;
		sx = x - 1 * i;
		ey = y + 1 * i;
		ex = x + 1 * i;
		
		// 초기화 
		vv.clear();
		dir = 0;
		memset(visited, 0, sizeof(visited));
		
		// 
		visited[sy][sx] = 1;
		vv.push_back({sy, sx});
		go(sy, sx, 1); // 이거 재귀로 돌아감 
		
		// 
		vector<int> vvv;
		
		// vv에 0번이 아닌 1번부터 들어가 있음
		for(pair<int, int> c : vv)
			vvv.push_back(b[c.f][c.s]);
			
		// 한칸씩 순서대로 밀고 
		rotate(vvv.begin(), vvv.begin() + vvv.size() - 1, vvv.end()); // (시작점, 칸수, 끝점)? // 칸수를 size() - 1로 하면서 오른쪽으로 한칸 이동하는 것으로 작동. 
		
		// 한칸씩 순서대로 넣기??? 
		for(int i = 0; i < vv.size(); i++)
			b[vv[i].f][vv[i].s] = vvv[i];		
	}
}

int solve(){
	for(int i : v_idx) // 회전 시키는 것 
		rotateAll(v[i].y, v[i].x, v[i].cnt);
	
	int _ret = INF;
	
	for(int i = 0; i < n; i++){
		int cnt = 0;
		for(int j = 0; j < m; j++)
			cnt += b[i][j];
		_ret = min(_ret, cnt);	
	}
	return _ret;
}

int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	
	for(int i = 0; i < k; i++){
		cin >> r >> c >> s;
		r--; c--;
		v.push_back({r, c, s});
		v_idx.push_back(i); // 이렇게 순서를 기억해놓고, permutation해서 v[i]로 뽑으면 됨. 
	}
	
	do{
		memcpy(b, a, sizeof(b));
		ret = min(ret, solve());
	}while(next_permutation(v_idx.begin(), v_idx.end()));
	
	cout << ret;
	return 0;
	
}

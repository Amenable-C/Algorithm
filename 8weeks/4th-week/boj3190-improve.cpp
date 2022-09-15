#include<bits/stdc++.h>
using namespace std;

#define time ff
#define y1 cc

typedef long long ll;
int n, k, l, y, x, t, ret, idx, dir = 1;
int a[104][104], visited[104][104], time;

char c;
deque<pair<int, int>> dq;
vector<pair<int, int>> _time;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	
	for(int i = 0; i < k; i++){
		cin >> y >> x;
		a[--y][--x] = 1;	
	}
	
	cin >> l;
	for(int i = 0; i < l; i++){
		cin >> t >> c;
		if(c == 'D')
			_time.push_back({t, 1}); // 오른쪽으로 진행 // 좌표축 다른거 항상 생각!!! 
		else
			_time.push_back({t, 3}); // 왼쪽으로 진행 
	}
	
	//
	dq.push_back({0, 0});
	while(dq.size()){
		time++;
		tie(y, x) = dq.front();
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny >= n || ny < 0 || nx >= n || nx < 0 || visited[ny][nx]) // 게임이 끝나는거 
			break;
		
		if(!a[ny][nx]){ // 사과가 없는 경우
			visited[dq.back().first][dq.back().second] = 0; // 꼬리를 0으로 만들기 
			dq.pop_back();  // dq에서 꼬리 없애기 
		}else // 사과 먹었다고 표시 
			a[ny][nx] = 0;
		
		visited[ny][nx] = 1; // 진행한 곳을 1로 만들기 
		dq.push_front({ny, nx}); // 진행 한 곳 dq에 넣기 
		if(time == _time[idx].first){
			dir = (dir + _time[idx].second) % 4; // 이렇게 해야지 현재 기준으로 회전이 됨!!! 
			idx++;
		}
	}
	cout << time;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define time ff
#define y1 cc

int n, k, a[104][104], visited[104][104], t, tt;
int time, dir = 1, m;
int l, r, y, x; 


int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

char c;
deque<pair<int, int>> dq;
vector<pair<int, int>> _time;

int main(){
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> l >> r;
		a[--l][--r] = 1;	
	}
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> tt >> c;
		if(c == 'D'){
			_time.push_back({tt, 1});	
		}
		else{
			_time.push_back({tt, 3});
		}
	}
	
	dq.push_back({0, 0});
	while(dq.size()){
		time++;
		tie(y, x) = dq.front();
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
			break;
			
		if(!a[ny][nx]){ // 사과가 없는 경우 
			visited[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		else{ // 사과가 있는 경우 
			a[ny][nx] = 0;
		}
		
		visited[ny][nx] = 1;
		dq.push_front({ny, nx});
		
		if(time == _time[m].first){
			dir = (dir + _time[m].second) % 4;
			m++;	
		}
	}

	cout << time;
	return 0;
}

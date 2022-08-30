#include <bits/stdc++.h>
using namespace std;

int n, m, s_x, s_y, e_x, e_y;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
char a[301][301];
int visited[301][301];
queue<int> q;


int main(){
	cin >> n >> m;
	cin >> s_y >> s_x >> e_y >> e_x;
	s_y--, s_x--, e_y--, e_x--;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	q.push(1000 * s_y + s_x);
	visited[s_y][s_x] = 1;
	
	int cnt = 0;
	
	while(a[e_y][e_x] != '0'){
		cnt++;
		queue<int> temp;
		
		while(q.size()){
			int y = q.front() / 1000;
			int x = q.front() % 1000;
			q.pop();
			
			for(int i = 0; i < 4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx])
					continue;
					
				visited[ny][nx] = cnt;
				
				if(a[ny][nx] != '0'){
					a[ny][nx] = '0';
					temp.push(ny * 1000 + nx);
				}
				else
					q.push(ny * 1000 + nx);
			}
		}
		q = temp;
	}
	cout << visited[e_y][e_x];
}

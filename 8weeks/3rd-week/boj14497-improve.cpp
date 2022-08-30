#include <bits/stdc++.h>
using namespace std;

char a[301][301];
int n, m, x1, y1, x2, y2;
typedef pair<int, int> pii;
int visited[301][301];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int ret;
queue<int> q;

int main(){
	cin >> n >> m;
	cin >> y1 >> x1 >> y2 >> x2;
	
	y1--, x1--, y2--, x2--; // 인덱스에 맞게 숫자 수정
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	q.push(1000 * y1 + x1); // 최대가 300이니깐 첫 자리수를 1000단위로 한것 
	visited[y1][x1] = 1;
	
	int cnt = 0;
	
	while(a[y2][x2] != '0'){ // 아직 도착을 못한경우 
		cnt++;
		queue<int> temp;
		
		while(q.size()){ // 상하좌우로 0을 계속 지나가기 위한 것.
			int y = q.front() / 1000;
			int x = q.front() % 1000;
			q.pop();
			
			for(int i = 0; i < 4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])
					continue;
				
				visited[ny][nx] = cnt;
				
				if(a[ny][nx] != '0'){ // 
					a[ny][nx] = '0';
					temp.push(1000 * ny + nx);
				}
				else // 0이면 q를 계속 쌓으면서 진행한다는거 // 여기서 cnt가 늘어나지는 않음. 
					q.push(1000 * ny + nx);
			}
		}  
		q = temp;
	}
	cout << visited[y2][x2];
}

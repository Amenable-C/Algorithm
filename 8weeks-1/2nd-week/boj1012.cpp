#include<bits/stdc++.h>
using namespace std;

const int max_n = 54;
int t, n, m, k, b_x, b_y, a[54][54], visited[54][54], ret, y, x;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main(){
	cin >> t;
	while(t--){
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
		ret = 0;
		
		cin >> m >> n >> k;
		for(int i = 0; i < k; i++){
			cin >> b_x >> b_y;
			a[b_y][b_x] = 1;
		}
		
		
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] == 1){
					ret++;
					
					queue<pair<int, int>> q;
					q.push({i, j});
					while(q.size()){
						tie(y, x) = q.front();
						q.pop();
						
						for(int v = 0; v < n; v++){
							int ny = y + dy[v];
							int nx = x + dx[v];
							if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0)
								continue;
							a[ny][nx] = 0;
							q.push({ny, nx});
						}
					}
				}
			}
		}
		cout << ret << "\n";	
	
	}
}

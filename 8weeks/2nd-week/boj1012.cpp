#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

const int max_n = 54;

int t, n, m, num, ret, a[max_n][max_n], visited[max_n][max_n], y, x, ny, nx;
int s_x, s_y;

int main(){
	cin >> t;
	for(int i = 0; i < t; i++){
		fill(&a[0][0], &a[0][0]	 + 54 * 54, 0);
		cin >> n >> m >> num;
		for(int j = 0; j < num; j++){
			cin >> s_x >> s_y;
			a[s_x][s_y] = 1;
		}
		
		for(int k = 0; k < n; k++){
			for(int p = 0; p < m; p++){
				if(a[k][p] == 0)
					continue;
				
				ret++;
				queue<pair<int, int>> q;
				q.push({k, p});
				
				while(q.size()){
					tie(y, x) = q.front();
					q.pop();
					
					for(int g = 0; g < 4; g++){
						ny = y + dy[g];
						nx = x + dx[g];
						
						if(ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 0)
							continue;
						
						a[ny][nx] = 0;
						q.push({ny, nx});
					}
				}
			}
		}
		
		cout << ret << endl;
		ret = 0;
	}
}

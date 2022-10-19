#include<bits/stdc++.h>
using namespace std;

const int max_n = 104;
int n, m, k, l_x, l_y, r_x, r_y, s_y, s_x, cnt_y, cnt_x, a[max_n][max_n], cnt, ret, y, x;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<int> v;

int main(){
	cin >> n >> m >> k;
	
	while(k--){
		cin >> l_x >> l_y >> r_x >> r_y;
		// y는 작아지고, x는 커지는 방향으로 칸 수만큼 진행만 하면됨.
		s_y = n - l_y - 1;
		s_x = l_x;
		cnt_y = r_y - l_y;
		cnt_x = r_x - l_x;
		
		// 1로 block시키기 
		for(int i = s_y; i > s_y - cnt_y; i--){
			for(int j = s_x; j < s_x + cnt_x; j++){
				a[i][j] = 1;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 0){
				cnt++;
				ret = 1;
				queue<pair<int, int>> q;
				q.push({i, j});
				a[i][j] = 1;
				while(q.size()){
					tie(y, x) = q.front();
					q.pop();
					
					for(int i = 0; i < 4; i++){
						int ny = y + dy[i];
						int nx = x + dx[i];
						if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 1)
							continue;
						
						q.push({ny, nx});
						a[ny][nx] = 1;
						ret++;
					}
				}
				v.push_back(ret);
			}
		}
		
	}
	cout << cnt << "\n";
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";	
	}
	return 0;
	
}

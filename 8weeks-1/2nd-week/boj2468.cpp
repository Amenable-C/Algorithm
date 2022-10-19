#include<bits/stdc++.h>
using namespace std;

const int max_n = 104;
int n, a[max_n][max_n], b[max_n][max_n], high, ret, cnt, y, x;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			high = max(high, a[i][j]);
		}
	}
	
	high--;
	while(high >= 0){
		
		
		ret = 0;
		memset(b, 0, sizeof(b));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(a[i][j] > high){
					b[i][j] = 1;			
				}
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(b[i][j] == 1){
					ret++;
					queue<pair<int, int>> q;
					q.push({i, j});
					while(q.size()){
						tie(y, x) = q.front();
						q.pop();
						
						for(int k = 0; k < 4; k++){
							int ny = y + dy[k];
							int nx = x + dx[k];
							
							if(ny < 0 || ny >= n || nx < 0 || nx >= n || b[ny][nx] == 0)
								continue;
							
							b[ny][nx] = 0;
							q.push({ny, nx});		
						}
					}
				}
			}	
		}
		
		cnt = max(cnt, ret);
		high--;
	}
	
	cout << cnt;
	return 0;
}

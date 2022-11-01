#include<bits/stdc++.h>
using namespace std;

int t, n, a[14][14], cnt, d, y, x, ny, nx;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n;
		cnt = 1;
		d = 0;
		y = 0, x = 0;
		memset(a, 0, sizeof(a));
		while(true){
			a[y][x] = cnt++;
			if(cnt == n * n + 1)
				break;
			ny = y + dy[d];
			nx = x + dx[d];
			//d = (d + 1) % 4;
			if(ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx]){
				d = (d + 1) % 4;
				ny = y + dy[d];
				nx = x + dx[d];
			}
			y = ny;
			x = nx;
		}
		
		cout << "#" << i << "\n";
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				cout << a[j][k] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}

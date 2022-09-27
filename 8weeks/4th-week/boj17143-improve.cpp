#include<bits/stdc++.h>
#define max_n 104
using namespace std;

struct Shark{
	int x, y, s, z, dir, death;	
}a[max_n * max_n];

// 속도 0 -> 정지, 1 -> 위, 2 -> 아래, 3 -> 오른쪽, 4 -> 왼쪽 
const int dx[] = {0, 0, 0, 1, -1};
const int dy[] = {0, -1, 1, 0, 0};

int _map[max_n][max_n], R, C, M , ret, temp[max_n][max_n];

int main(){
	cin >> R >> C >> M;
	for(int i = 1; i <= M; i++){
		cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;
		a[i].y -= 1; a[i].x -= 1;
		_map[a[i].y][a[i].x] = i;
	}
	
	for(int t = 0; t < C; t++){
		// 1. 상어를 잡는 것. 
		for(int y = 0; y < R; y++){
			if(_map[y][t]){ // 상어가 있는 경우 
				a[_map[y][t]].death =  1;
				ret += a[_map[y][t]].z; // 사이즈 만큼 ret 추가 
				_map[y][t] = 0; // 삭제
				break; 
			}
		}
		
		// 2. 초기화
		memset(temp, 0, sizeof(temp)); 
		for(int i = 1; i <= M; i++){
			if(a[i].death)
				continue;
			
			int _y = a[i].y;
			int _x = a[i].x;
			int s = a[i].s;
			int d = a[i].dir;
			int ny, nx;
			
			while(1){
				ny = _y + s * dy[d];
				nx = _x + s * dx[d];
				if(nx < C && ny < R && ny >= 0 && nx >= 0) // 범위 안에 있는 경우 => 계산 끝 
					break; 
				if(d == 1 && ny < 0){
					s -= _y;
					_y = 0;
					d = 2;
				}
				else if(d == 2 && ny >= R){
					s -= R - 1 - _y; 
					_y = R - 1; 
					d = 1;
				}
				else if(d == 3 && nx >= C){
					s -= C - 1 - _x; 
					_x = C - 1; 
					d = 4;
				}
				else if(d == 4 && nx < 0){
					s -= _x; 
					_x = 0; 
					d = 3;
				}	
			}
			
			if(temp[ny][nx]){
				if (a[temp[ny][nx]].z < a[i].z) { 
					a[temp[ny][nx]].death = 1; 
					temp[ny][nx] = i; 
				}
                else 
					a[i].death = 1;
			}
			else
				temp[ny][nx] = i;
			
			a[i].x = nx;
			a[i].y = ny;
			a[i].dir = d;
		}
		for(int y = 0; y < R; y++){
			for(int x = 0; x < C; x++){
				_map[y][x] = temp[y][x];	
			}
		}
	}
	cout << ret;
	return 0;
}




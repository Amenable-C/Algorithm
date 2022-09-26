#include<bits/stdc++.h>
using namespace std;

int R, C, M, ret;
int r, c;
int m[104][104], a[10004][10], no_exist[10004];
// a -> r, c, s, d, z -> r, c, 속도, 방향, 사이즈 



int eating(int idx){	
	for(int i = 0; i < R; i++){
		if(m[i][idx]){
			no_exist[m[i][idx]] = 1; // 해당 상어는 먹혀서 존재하지 않는 것! 
			return a[m[i][idx]][4]; // 해당 상어의 사이즈를 return 
		}
	}
	return 0; 
}

void sharks_move(){
	memset(m, 0, sizeof(m)); // 현재 상어 위치 초기화 // 새로운 공간에 상어를 배치할 것이라서 
	
	for(int i = 1; i <= M; i++){
		if(no_exist[i]){ // 잡아먹혀서 없는 경우 
			continue; 
		}
		
		for(int j = 0; j < a[i][2]; j++){ // 속도만큼 움직이는 것 
			if(a[i][3] == 1){ // 위로 이동 
				if(a[i][0] == 0){ // 막혀있는 경우 
					a[i][3] = 2; // 아래로 방향 전환 
					a[i][0]++; // 아래로 이동 
				}
				else{
					a[i][0]--; 
				}
			}
			else if(a[i][3] == 2){ // 밑으로 이동
				if(a[i][0] == R-1){ // 막혀있는 경우 
					a[i][3] = 1; // 위쪽으로 방향 전환 
					a[i][0]--; // 위로 이동 
				}
				else{
					a[i][0]++; 
				}
			}
			else if(a[i][3] == 3){ // 오른쪽으로 이동 
				if(a[i][1] == C - 1){
					a[i][3] = 4;
					a[i][1]--;
				}
				else{
					a[i][1]++;
				}
			}
			else if(a[i][3] == 4){ // 왼쪽으로 이동 
				if(a[i][1] == 0){
					a[i][3] = 3;
					a[i][1]++;
				}
				else{
					a[i][1]--;
				}
			}
			
		}

		// 이동을 마친 후 맵에 상어 번호 매기기 
		if(m[a[i][0]][a[i][1]]){ // 이미 상어가 있는 경우 
			if(m[a[i][0]][a[i][1]] > a[i][4]){ // 기존꺼가 더 큰 경우 
				no_exist[i] = 1; // 기존꺼에 잡아 먹힌  것 
			}
			else{
				no_exist[m[a[i][0]][a[i][1]]] = 1; // 기존꺼 잡아먹기
				m[a[i][0]][a[i][1]] = i; // 새롭게 맵 갱신 
			}
		}
		else{
			m[a[i][0]][a[i][1]] = i;
		}
	}
	return;
}

int person_go(int idx){
	int size = eating(idx);
	
	sharks_move();
	
	return size;
}


int main(){
	cin >> R >> C >> M;
	for(int i = 1; i <= M; i++){
		cin >> r >> c >> a[i][2] >> a[i][3] >> a[i][4];
		r--; c--;
		a[i][0] = r;
		a[i][1] = c;
		
		if(m[r][c]){ // 이미 상어가 있는 경우 
			if(m[r][c] > a[i][4]){ // 기존꺼가 더 큰 경우 
				no_exist[i] = 1; // 기존꺼에 잡아 먹힌  것 
			}
			else{
				no_exist[m[r][c]] = 1; // 기존꺼 잡아먹기
				m[r][c] = i; // 새롭게 맵 갱신 
			}
		}
		else{
			m[r][c] = i;
		}
	}
	
	if(M == 0){
		cout << 0;
		return 0;	
	}
	
	for(int i = 0; i < C; i++){
		ret += person_go(i);
	}
		
	cout << ret;
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int R, C, M, ret;
int r, c;
int m[104][104], a[10004][10], no_exist[10004];
// a -> r, c, s, d, z -> r, c, �ӵ�, ����, ������ 



int eating(int idx){	
	for(int i = 0; i < R; i++){
		if(m[i][idx]){
			no_exist[m[i][idx]] = 1; // �ش� ���� ������ �������� �ʴ� ��! 
			return a[m[i][idx]][4]; // �ش� ����� ����� return 
		}
	}
	return 0; 
}

void sharks_move(){
	memset(m, 0, sizeof(m)); // ���� ��� ��ġ �ʱ�ȭ // ���ο� ������ �� ��ġ�� ���̶� 
	
	for(int i = 1; i <= M; i++){
		if(no_exist[i]){ // ��Ƹ����� ���� ��� 
			continue; 
		}
		
		for(int j = 0; j < a[i][2]; j++){ // �ӵ���ŭ �����̴� �� 
			if(a[i][3] == 1){ // ���� �̵� 
				if(a[i][0] == 0){ // �����ִ� ��� 
					a[i][3] = 2; // �Ʒ��� ���� ��ȯ 
					a[i][0]++; // �Ʒ��� �̵� 
				}
				else{
					a[i][0]--; 
				}
			}
			else if(a[i][3] == 2){ // ������ �̵�
				if(a[i][0] == R-1){ // �����ִ� ��� 
					a[i][3] = 1; // �������� ���� ��ȯ 
					a[i][0]--; // ���� �̵� 
				}
				else{
					a[i][0]++; 
				}
			}
			else if(a[i][3] == 3){ // ���������� �̵� 
				if(a[i][1] == C - 1){
					a[i][3] = 4;
					a[i][1]--;
				}
				else{
					a[i][1]++;
				}
			}
			else if(a[i][3] == 4){ // �������� �̵� 
				if(a[i][1] == 0){
					a[i][3] = 3;
					a[i][1]++;
				}
				else{
					a[i][1]--;
				}
			}
			
		}

		// �̵��� ��ģ �� �ʿ� ��� ��ȣ �ű�� 
		if(m[a[i][0]][a[i][1]]){ // �̹� �� �ִ� ��� 
			if(m[a[i][0]][a[i][1]] > a[i][4]){ // �������� �� ū ��� 
				no_exist[i] = 1; // �������� ��� ����  �� 
			}
			else{
				no_exist[m[a[i][0]][a[i][1]]] = 1; // ������ ��ƸԱ�
				m[a[i][0]][a[i][1]] = i; // ���Ӱ� �� ���� 
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
		
		if(m[r][c]){ // �̹� �� �ִ� ��� 
			if(m[r][c] > a[i][4]){ // �������� �� ū ��� 
				no_exist[i] = 1; // �������� ��� ����  �� 
			}
			else{
				no_exist[m[r][c]] = 1; // ������ ��ƸԱ�
				m[r][c] = i; // ���Ӱ� �� ���� 
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

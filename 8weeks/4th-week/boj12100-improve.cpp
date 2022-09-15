#include<bits/stdc++.h>
using namespace std;

int ret, n;

struct Board{
	int a[24][24];
	
	// ȸ�� ��Ű�� �� // �ܿ��! 
	void _rotate90(){
		int temp[24][24];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				temp[i][j] = a[n - j - 1][i];	
			}
		}
		memcpy(a, temp, sizeof(a)); 
	}
	
	void _move(){
		int temp[24][24];
		for(int i = 0; i < n; i++){
			int c = -1, d = 0; // d�� ���ӵǴ� ���� ����. 
			for(int j = 0; j < n; j++){
				if(a[i][j] == 0) // ó�����ٰ� �ƹ��͵� ���� ��� 
					continue;
				if(d && a[i][j] == temp[i][c]) // �տ� ���ڰ� �ְ� && ��ĥ �� �ִ� ��� 
					temp[i][c] *= 2, d = 0;
				else
					temp[i][++c] = a[i][j], d = 1; 
			}
			for(c++; c < n; c++) // ���� �κ� 0���� ä��� 
				temp[i][c] = 0;	
		}
		memcpy(a, temp, sizeof(a));
	}
	
	
	// �������� �ִ밪 ã�� �� 
	void get_max(){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				ret = max(ret, a[i][j]);
			}
		}
	}
};

void go(Board c, int here){
	if(here == 5){
		c.get_max(); // ret�� ���� ū ���� �ٲٴ� �� 
		return; 
	}
	
	for(int i = 0; i < 4; i++){
		Board d = c;
		d._move();
		go(d, here + 1);
		c._rotate90();
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	
	Board c;
	
	// 1. �Է�
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>> c.a[i][j];
		}
	}
	
	go(c, 0);
	cout << ret;
	return 0;
}

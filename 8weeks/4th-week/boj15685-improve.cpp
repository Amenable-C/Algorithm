#include<bits/stdc++.h>
using namespace std;

/*
<��Ģ>
������ ã�Ƽ� �������� �������� �� ���� �׸��� �� 

0
1
2 1
2 3 2 1
2 3 0 3 2 3 2 1

('���� �迭�� ���� + 1' % 4) + (���� �迭 �״��)
*/

// ������ �������� �ƴ϶� �������� �ִ°ɷ� ���� ����� 
const int dy[] = {0, -1, 0 , 1};
const int dx[] = {1, 0, -1, 0};

vector<int> dragon[4][11];
int cnt, n, x, y, d, g, a[101][101];

void go(int x, int y, int d, int g){
	int _x = x;
	int _y = y;
	a[_x][_y] = 1; // ������ ����
	for(int i = 0; i <= g; i++){ // 
		for(int dir : dragon[d][i]){ // vector�� �ִ� ����� ��� ����ϴ� �� // �׸��� ����ؼ� ������ �̾���� �� 
			_x += dx[dir];
			_y += dy[dir];
			a[_x][_y] = 1;	
		}
	}
	return;
}

// 4���� ������ �������� 10������� ���⼺�� ����
void makeDragon(){
	for(int i = 0; i < 4; i++){
		dragon[i][0].push_back(i);
		dragon[i][1].push_back((i + 1) % 4);
		for(int j = 2; j <= 10; j++){
			int _n = dragon[i][j - 1].size();
			for(int k = _n - 1; k >= 0; k--){
				dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4); // ('���� �迭�� ���� + 1' % 4)
			}
			for(int k = 0; k < _n; k++){
				dragon[i][j].push_back(dragon[i][j - 1][k]); // (���� �迭 �״��)
			}
		}
	}
	return;
}

int main(){
	cin >> n;
	makeDragon();
	
	for(int i = 0; i < n; i++){
		cin >> x >> y >> d >> g;
		go(x, y, d, g);	// �巡�� Ŀ�� ����� 
	}
	
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			if(a[i][j] && a[i + 1][j] && a[i + 1][j + 1] && a[i][j + 1]) // 1x1�� ���簢���� �� �������� ��� �巡�� Ŀ���ΰ� ã��
				cnt++;
		}
	}
	
	cout << cnt;
	return 0;
}
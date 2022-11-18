#include<iostream>
#include<memory.h>
using namespace std;

int t, n, flag; 
char a[24][24];

bool right(int y, int x) {
	int cnt = 0;
	for (cnt = 0; cnt < 5; cnt++) {
		if (x >= n)
			break;
		if (a[y][x] == '.')
			break;
		x++;
	}
	return cnt == 5;
}

bool down(int y, int x) {
	int cnt = 0;
	for (cnt = 0; cnt < 5; cnt++) {
		if (y >= n)
			break;
		if (a[y][x] == '.')
			break;
		y++;
	}
	return cnt == 5;
}

bool rightDown(int y, int x) {
	int cnt = 0;
	for (cnt = 0; cnt < 5; cnt++) {
		if (x >= n || y >= n)
			break;
		if (a[y][x] == '.')
			break;
		y++;
		x++;
	}
	return cnt == 5;
}

bool leftDown(int y, int x) {
	int cnt = 0;
	for (cnt = 0; cnt < 5; cnt++) {
		if (x < 0 || y >= n)
			break;
		if (a[y][x] == '.')
			break;
		y++;
		x--;
	}
	return cnt == 5;
}


int main() {
	cin >> t;
	for (int _t = 1; _t <= t; _t++) {
		cin >> n;
		flag = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 'o') {
					if (right(i, j) || down(i, j) || rightDown(i, j) || leftDown(i, j)){
						flag = 1;
						break;
					}
				}
			}
			if (flag)
				break;
		}

		if (flag) {
			cout << "#" << _t << " YES\n";
		}
		else {
			cout << "#" << _t << " NO\n";
		}


	}


}
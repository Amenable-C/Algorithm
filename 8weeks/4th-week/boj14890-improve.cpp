#include <bits/stdc++.h>
using namespace std;

int n, l, a[104][104], b[104][104], ret;

void solve(int a[104][104]){
	for(int i = 0; i < n; i++){
		int cnt = 1;
		int j;
		for(j = 0; j < n - 1; j++){
			if(a[i][j] == a[i][j+1])
				cnt++;
			else if(a[i][j] + 1 == a[i][j+1] && cnt >= l) // 올라가는거 // 그 전에 l보다 긴 칸이 있어야 함.  
				cnt = 1;
			else if(a[i][j] - 1 == a[i][j+1] && cnt >= 0) // 내려가는거 // 뒤에 l-1칸 만큰 더 +가 되어야 함. 
				cnt = -l + 1;
			else break;
		}
		if(j == n - 1 && cnt >= 0)
			ret++;
	}
	return;
}


int main(){
	cin >> n >> l;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			b[j][i] = a[i][j]; // 행 기준, 열 기준을 따로 하는게 아니라 한번에 돌리기 위한것	
		}
	}
	
	solve(a);
	solve(b);
	cout << ret;
	return 0;
	
}

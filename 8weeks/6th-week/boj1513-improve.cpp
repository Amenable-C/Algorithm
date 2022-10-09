#include<bits/stdc++.h>
using namespace std;

int n, m, c, y, x, a[51][51], dp[51][51][51][51];
const int mod = 1000007;

int go(int y , int x, int cnt, int prev){
	if(y > n || x > m) // ������ ����� ��� 
		return 0;
	if(y == n && x == m){ // �п�(������ ����)�� ������ ��� 
		if(cnt == 0 && a[y][x] == 0) // �������̶� ������ �������� ��ġ���� �ʴ� ���. 
			return 1;
		if(cnt == 1 && a[y][x] > prev) // �������̶� ������ �������� ��ġ�ϴ� ���.  
			return 1;
		return 0; // ���ǿ� ���� ���� ���� 0�� return 
	}
	
	int &ret = dp[y][x][cnt][prev];
	if(ret != -1){ // �̹� ������ ��� 
		return ret; 
	}
	
	ret = 0;
	if(a[y][x] == 0){ // ���� ��ġ�� �������� �ƴ� ���.
		ret = (go(y + 1, x, cnt, prev) + go(y, x + 1, cnt, prev)) % mod; 
	} 
	else if(a[y][x] > prev){ // ���� ��ġ�� �������� ���. 
		ret = (go(y + 1, x, cnt - 1, a[y][x]) + go(y, x + 1, cnt - 1, a[y][x])) % mod;		
	}
	return ret;
}
 


int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> c;
	for(int i = 1; i <= c; i++){ // �ʱ� prev�� 0���� �����ҰŶ� 1���� ����. 
		cin >> y >> x;
		a[y][x] = i; // �������� ��ȣ�� �ο��ϸ鼭 ��ġ ����	
	}
	
	for(int i = 0; i <= c; i++){ // 0�� �湮, 1�� �湮, 2�� �湮, ... , c�� �湮 
		cout << go(1, 1, i, 0) << " ";
	}
	return 0;
}

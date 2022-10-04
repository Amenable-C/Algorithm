#include<bits/stdc++.h>
#define MAX_N 16
using namespace std;

const int INF = 987654321;

int n, dp[MAX_N][1 << MAX_N], dist[MAX_N][MAX_N];

int tsp(int here, int visited){ // ��Ʈ����ŷ���� �湮�� ���� �ѹ��� ǥ��
	if(visited == (1 << n) - 1){ // n���� ���ø� ��� �湮���� ���, visited => (1 << n) - 1
		return dist[here][0] ? dist[here][0] : INF; // �� �� ���� ��츦 ����� �� 
	}
	
	int &ret = dp[here][visited];
	if(ret != -1) // �̹� �ּҰ��� ���� �� ��� 
		return ret;
		
	ret = INF; // �ʱ�ȭ
	for(int i = 0; i < n; i++){
		if(visited & (1 << i)) // i��° ���ø� �湮���� ���� ��� 
			continue;
		if(dist[here][i] == 0) // �� �� ���� ��� 
			continue;
		ret = min(ret, tsp(i, visited | (1 << i)) + dist[here][i]); // i��° ���ÿ��� ���� ���� �̿��ؼ� here�� �ּҰ� ���� 
	}
	return ret;	
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> dist[i][j];
		}
	}
	
	memset(dp, -1, sizeof(dp));
	cout << tsp(0, 1);
	return 0;
}

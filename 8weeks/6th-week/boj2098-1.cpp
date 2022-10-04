#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;

int n, cost[16][16], dp[16][1<<16];

int tsp(int here, int visited){
	if(visited == (1 << n) - 1){
		return cost[here][0] ? 	cost[here][0] : INF;
	}
	
	int &ret = dp[here][visited];
	if(~ret)
		return ret;
	
	ret = INF;
	for(int i = 0; i < n; i++){
		if(visited & (1 << i)) // �̹� �ش� ���ø� �湮�� ��� 
			continue;
		if(cost[here][i] == 0) // �� �� ���� ��� 
			continue;
		ret = min(ret, tsp(i, visited | (1 << i)) + cost[here][i]);
	}
	return ret; 
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> cost[i][j];	
		}
	}
	
	memset(dp, -1, sizeof(dp));
	
	cout << tsp(0, 1);
	return 0;
	
}

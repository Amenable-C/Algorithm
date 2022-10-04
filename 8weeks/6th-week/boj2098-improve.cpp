#include<bits/stdc++.h>
#define MAX_N 16
using namespace std;

const int INF = 987654321;

int n, dp[MAX_N][1 << MAX_N], dist[MAX_N][MAX_N];

int tsp(int here, int visited){ // 비트마스킹으로 방문한 곳을 한번에 표현
	if(visited == (1 << n) - 1){ // n개의 도시를 모두 방문했을 경우, visited => (1 << n) - 1
		return dist[here][0] ? dist[here][0] : INF; // 갈 수 없는 경우를 고려한 것 
	}
	
	int &ret = dp[here][visited];
	if(ret != -1) // 이미 최소값이 결정 난 경우 
		return ret;
		
	ret = INF; // 초기화
	for(int i = 0; i < n; i++){
		if(visited & (1 << i)) // i번째 도시를 방문하지 않은 경우 
			continue;
		if(dist[here][i] == 0) // 갈 수 없는 경우 
			continue;
		ret = min(ret, tsp(i, visited | (1 << i)) + dist[here][i]); // i번째 도시에서 오는 것을 이용해서 here의 최소값 갱신 
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

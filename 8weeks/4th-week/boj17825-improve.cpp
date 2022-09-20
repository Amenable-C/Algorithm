#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int a[14], mal[4], n = 10;
int v[104];

vector<int> adj[54];

int move(int here, int cnt){
	if(here == 100) // 도착지점인 경우 칸의 idx인 100을 return 
		return 100;
	if(adj[here].size() >= 2){ // 처음으로 말이 이동할 때, 방향이 2개인 경우 -> 파란색으로 가야함([1]로 가야함) 
		here = adj[here][1];
		cnt--; // 이동했으므로 cnt 줄이기 
	}
	
	// 이동 횟수가 남은 경우
	if(cnt){
		queue<int> q;
		q.push(here);
		int there;
		while(q.size()){
			int x = q.front();
			q.pop();
			there = adj[x][0];
			q.push(there);
			
			if(there == 100) // 도착 지점인 경우 
				break;
			cnt--;
			if(cnt == 0)
				break;	
			
		}
		return there;
	}
	else{
		return here;
	}
}

bool isMal(int mal_idx, int idx){
	if(mal_idx == 100) // 이동을 마치는 칸이 도착 칸인 경우 
		return false;
	for(int i = 0; i < 4; i++){
		if(i == idx) // 자기 자신 
			continue;
		if(mal[i] == mal_idx) // 이동을 마치는 칸에 다른 말이 있는 경우 = 고를 수 없음 (이게 무슨 말이지??) 
			return true;
	}
	return false; // 이동을 마치는 칸이 도착 칸이 아니고, 다른 말도 다 없는 경우 
}

void add(int here, int there){
	adj[here].push_back(there);	
}

// 위치와 해당 위치에 대한 점수를 따로 나타내어야 함.
// 1. 위치 -> vector<pair<int, int>> adj;
// 방향이 2개 존재하는것도 있기 때문에 push_back으로 넣고, [0]과 [1]을 이용하는 것 
// 2. 해당 위치에 대한 점수 -> int v[] 
void setMap(){
	for(int i = 0; i <=19; i++){
		add(i, i+1);
	}
	add(5, 21); add(21, 22); add(22, 23); add(23, 24);
	add(15, 29); add(29, 30); add(30, 31); add(31, 24); 
	
	add(10, 27); add(27, 28); add(28, 24); add(24, 25);
	add(25, 26); add(26, 20); add(20, 100);
	
	v[1] = 2; v[2] = 4;  v[3] = 6; v[4] = 8; v[5] = 10; 
	v[6] = 12; v[7] = 14; v[8] = 16; v[9] = 18; v[10] = 20; 
	v[11] = 22; v[12] = 24; v[13] = 26; v[14] = 28; v[15] = 30; 
	v[16] = 32; v[17] = 34; v[18] = 36; v[19] = 38; v[20] = 40; 
	v[21] = 13; v[22] = 16; v[23] = 19;  v[24] = 25; 
	v[27] = 22; v[28] = 24; v[25] = 30; v[26] = 35; 
	v[29] = 28; v[30] = 27; v[31] = 26; 
}

int go(int here){
	if(here == n) // 0부터 시작하므로 10이면 return 0; 
		return 0;
		
	int ret = 0;
	
	// 4개 중에 하나씩 다 선택하고 -> 4
	// 거기서 또 하나씩 다 선택하고 -> 4 x 4
	// 또, 하나씩 다 선택하면서 나아가는 거 -> 결국 모든 경우의 수를 탐색하는 것 
	for(int i = 0; i < 4; i++){
		int temp_idx = mal[i];
		int mal_idx = move(temp_idx, a[here]); // move(현재 위치, 움직일 수 있는 횟수) 
		if(isMal(mal_idx, i)) // 말이 이동을 마칠때 다른 말이 있는지 또는 도착 칸인지를 확인하는 것 
			continue;
		
		mal[i] = mal_idx; 
		ret = max(ret, go(here + 1) + v[mal_idx]); // 해당 말의 점수를 더하고 다음 스텝으로 넘어가는 행위 
		mal[i] = temp_idx; // 해당 스텝에서 다른 말들이 움직일 수 있도록 하는 것!! 
	}
	
	return ret;
}

int main(){
	setMap();
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	cout << go(0);
	return 0;
}

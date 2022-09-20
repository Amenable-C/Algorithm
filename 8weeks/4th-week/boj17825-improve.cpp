#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int a[14], mal[4], n = 10;
int v[104];

vector<int> adj[54];

int move(int here, int cnt){
	if(here == 100)
		return 100; // 나간 경우 칸을 100으로 설정해놓음 
	if(adj[here].size() >= 2){ // 처음으로 말이 이동하는 경우 
		here = adj[here][1];
		cnt--;
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
			
			if(there == 100)
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
	if(mal_idx == 100) // 이동을 마치는 칸에 있는 경우 
		return false;
	for(int i = 0; i < 4; i++){
		if(i == idx)
			continue;
		if(mal[i] == mal_idx)
			return true;
	}
	return false;
}

void add(int here, int there){
	adj[here].push_back(there);	
}

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
	
	for(int i = 0; i < 4; i++){
		int temp_idx = mal[i];
		int mal_idx = move(temp_idx, a[here]); // move(현재 위치, 움직일 수 있는 횟수) 
		if(isMal(mal_idx, i))
			continue;
		
		mal[i] = mal_idx; 
		ret = max(ret, go(here + 1) + v[mal_idx]); // 계속 비교하는게 아니라 마지막을 위해서 max를 쓰는거? 
		mal[i] = temp_idx;	
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

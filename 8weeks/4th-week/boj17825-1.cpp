#include<bits/stdc++.h>
using namespace std;

int point[104], mal[4], a[15];
vector<int> pos[54];

int move(int here, int cnt){
	if(here == 100)
		return 100;
		
	if(pos[here].size() >= 2){
		here = pos[here][1];
		cnt--;
	}
	
	if(cnt){
		queue<int> q;
		q.push(here);
		int there;
		while(q.size()){
			int x = q.front();
			q.pop();
			there = pos[x][0];
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

bool is_mal(int here, int mal_num){
	if(here == 100)
		return false;
	
	for(int i = 0; i < 4; i++){
		if(mal_num == i)
			continue;
			
		if(here == mal[i]){
			return true;
		}
	}
	return false;
}

void add(int here, int there){
	pos[here].push_back(there);
}

void setMap(){
	// node 연결 
	for(int i = 0; i <=19; i++){
		add(i, i+1);
	}
	add(5, 21); add(21, 22); add(22, 23); add(23, 24);
	add(15, 29); add(29, 30); add(30, 31); add(31, 24); 
	
	add(10, 27); add(27, 28); add(28, 24); add(24, 25);
	add(25, 26); add(26, 20); add(20, 100);
	
	// point
	point[1] = 2; point[2] = 4;  point[3] = 6; point[4] = 8; point[5] = 10; 
	point[6] = 12; point[7] = 14; point[8] = 16; point[9] = 18; point[10] = 20; 
	point[11] = 22; point[12] = 24; point[13] = 26; point[14] = 28; point[15] = 30; 
	point[16] = 32; point[17] = 34; point[18] = 36; point[19] = 38; point[20] = 40; 
	point[21] = 13; point[22] = 16; point[23] = 19; point[24] = 25; 
	point[27] = 22; point[28] = 24; point[25] = 30; point[26] = 35; 
	point[29] = 28; point[30] = 27; point[31] = 26; 
}

int go(int num){
	if(num == 10){
		return 0;	
	}
	
	int ret = 0; // 4번 다 돌고 난 후 최고 점수를 return 해줄거라서 0으로 초기화 하기 
	
	for(int i = 0; i < 4; i++){
		int tmp_idx = mal[i];
		int mal_idx = move(tmp_idx, a[num]);
		if(is_mal(mal_idx, i))
			continue;
		
		
		mal[i] = mal_idx;
		ret = max(ret, go(num + 1) + point[mal_idx]);
		mal[i] = tmp_idx;
	}
	return ret;
}

int main(){
	
	setMap();
	
	for(int i = 0; i < 10; i++){
		cin >> a[i];	
	}
	
	cout << go(0);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int t, a, d[54][54];
string s;
char b[54][54];
bool check[54][54];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

bool in(int aa, int bb){
	return (1 <= aa && aa <=t && 1 <= bb && bb <= a);	
}

int down(int y, int x){
	if(!in(y, x) || b[y][x] == 'H')
		return 0;
		
	if(check[y][x]){ // 한번 지나간 곳을 돌아온 경우 => 계속 돌 수 있다는 말 
		cout << -1 << "\n";
		exit(0);	
	}
	
	int &ret = d[y][x];
	if(ret)
		return ret;
	
	check[y][x] = 1;
	int value = (int)b[y][x] - '0'; // 문자랑 섞여있는 경우 이렇게 처리하기. 
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i] * value;
		int nx = x + dx[i] * value;
		ret = max(ret, down(ny, nx) + 1); // 기존꺼 vs 새로운거	
	}
	check[y][x] = 0; // 반복문에서 y, x에 대한 계산이 이루어지느거고, 밖에서는 다시 초기화 해줘야함. 
	return ret; 
	
}

int main(){
	cin >> t >> a;
	for(int i = 1; i <= t; i++){
		cin >> s;
		for(int j = 1; j <= a; j++){
			b[i][j] = s[j-1];	
		}
	}
	cout << down(1, 1);
	return 0;
}

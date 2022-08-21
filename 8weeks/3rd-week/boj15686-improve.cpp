#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
vector<pi> chs;
vector<pi> homes;
vector<vector<int>>chickenList;

int n, m, num;
int each;
int a[54][54];
int tot=1000000;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void combi(int start, vector<int> v){
	if(v.size() == m){ // 완성된 m개를 chickenList에 넣는것. // 순서를 넣어놓음. 
		chickenList.push_back(v);
		return;
	}
	for(int i = start + 1; i < chs.size(); i++){
		v.push_back(i);
		combi(i, v);
		v.pop_back();	
	}
	
}


int main(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			
			if(a[i][j] == 1){
				homes.push_back(pi(i, j));	
			}
			else if(a[i][j] == 2){
				chs.push_back(pi(i, j));
				
			}
		}
	}
	
	
	// ch m개 뽑고, home 와 거리 다 구하기 // 중복나와도 딱히 상관은 없음. -> 시간복잡도에서 문제 combi 넣어야함!!
	vector<int> v;
	combi(-1, v); // 한방에 나올 수 있는 combi를 전체 저장 
	
	for(vector<int> cList : chickenList){
		each = 0;
		for(int i = 0; i < homes.size(); i++){
			int dis = 300; 
			for(int ch : cList){
				dis = min(abs(homes[i].first - chs[ch].first) + abs(homes[i].second - chs[ch].second), dis);
				
			}
			each += dis;
		}
		tot = min(tot, each);
	}
		 
	cout << tot;
}

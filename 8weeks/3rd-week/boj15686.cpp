#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
vector<pi> chs;
vector<pi> homes;

int n, m, num;
int each;
int a[54][54];
int tot=1000000;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int go(int y, int x){
	
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
	
	
	// ch m개 뽑고, home 와 거리 다 구하기 // 중복나와도 딱히 상관은 없음. 
	do{
		each = 0;
		for(int i = 0; i < homes.size(); i++){
			int dis = 300; 
			for(int j = 0; j < m; j++){
				dis = min(abs(homes[i].first - chs[j].first) + abs(homes[i].second - chs[j].second), dis);
			}
			each += dis;
		}
		tot = min(tot, each);
	}
	while(next_permutation(chs.begin(), chs.end()));
	 
	cout << tot;

}

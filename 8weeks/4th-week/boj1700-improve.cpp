#include<bits/stdc++.h>
using namespace std;

int k, n, a[104], visited[104], cnt;
const int INF = 987654321;
vector<int> v;

int main(){
	cin >> k >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];	
	}
	for(int i = 0; i < n; i++){
		if(!visited[a[i]]){ // 제품이 멀티탭에 꼽혀있지 않은 경우(꼽혀있는 경우는 그냥 진행하는것!) 
			if(v.size() == k){ // 멀티탭이 꽉 찬 경우 
				int last_idx = 0, pos; 
				for(int _a : v){
					int here_pick = INF;
					for(int j = i + 1; j < n; j++){
						if(_a == a[j]){
							here_pick = j;
							break;	
						}	
					}
					if(last_idx < here_pick){ // 더 뒤에 있는 경우 // here_pick을 INF로 초기화 해줌으로써 하나라도 선택되게 하는것 
						last_idx = here_pick;
						pos = _a;
					}
				}
				visited[pos] = 0;
				cnt++;
				v.erase(find(v.begin(), v.end(), pos)); 
			}
			v.push_back(a[i]);
			visited[a[i]] = 1;
		}
	}
	cout << cnt;
	return 0; 
}

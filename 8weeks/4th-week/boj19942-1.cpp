#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;

int n, mp, mf, ms, mv, cost;
int p, f, s, v, c;
int ret = INF;
map<int, vector<vector<int>>> ret_v;


struct A{
	int mp, mf, ms, mv, cost;
}a[16];

int main(){
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	
	for(int i = 0; i < n; i++){
		cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
	}
	
	for(int i = 1; i < (1 << n); i++){
		p = f = s = v = c = 0;
		vector<int> _v;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				_v.push_back(j+1);
				p += a[j].mp;
				f += a[j].mf;
				s += a[j].ms;
				v += a[j].mv;
				c += a[j].cost;
			}
		}
		
		if(p >= mp && f >= mf && s >= ms && v >= mv){
			if(ret >= c){
				ret = c;
				ret_v[ret].push_back(_v);
			}
		}
	}
	
	if(ret == INF)
		cout << -1;
	else{
		sort(ret_v[ret].begin(), ret_v[ret].end()); // 비용이 가장 작은것들을 사전순으로 정렬 
		cout << ret << "\n";
		for(int a : ret_v[ret][0]){ // 비용이 같은것이 여러개일떄 사전순으로 가장 빠른거 출력 
			cout << a << " ";
		}
	}
	return 0;
}

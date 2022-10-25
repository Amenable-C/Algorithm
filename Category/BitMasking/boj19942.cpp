#include<bits/stdc++.h>
using namespace std;

int n, mp, mf, ms, mv, ret_c = 987654321, ret_b;
map<int, vector<vector<int>>> ret_v;

struct Food{
	int p;
	int f;
	int s;
	int v;
	int c;
};

int main(){
	cin >> n >> mp >> mf >> ms >> mv;
	Food fd[20];
	for(int i = 0; i < n; i++){
		cin >> fd[i].p >> fd[i].f >> fd[i].s >> fd[i].v >> fd[i].c;
	}
	
	for(int i = 1; i < (1 << n); i++){
		int c_p = 0, c_f = 0, c_s = 0, c_v = 0, c_c = 0;
		vector<int> v; 
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				v.push_back(j + 1);
				c_p += fd[j].p;
				c_f += fd[j].f;
				c_s += fd[j].s;
				c_v += fd[j].v;
				c_c += fd[j].c;
			}
		}
		if(c_p >= mp && c_f >= mf && c_s >= ms && c_v >= mv && c_c <= ret_c){
			ret_c = c_c;
			ret_b = i;
			ret_v[ret_c].push_back(v); 
		}
	}
	
	if(ret_c == 987654321){
		cout << -1;
		return 0;	
	}
	else{
		sort(ret_v[ret_c].begin(), ret_v[ret_c].end());  
		cout << ret_c << "\n";
		for(int a : ret_v[ret_c][0]){ // 사전순으로 앞서는 것 
			cout << a << " ";
		} 
	}
	return 0;
}

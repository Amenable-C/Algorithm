#include<bits/stdc++.h>
using namespace std;

int n, k, visited[100004];
int ret = 987654321;
map<int, int> _m;

void go(int here, int cnt){
	if(cnt > ret)
		return;
	
	if(here == k){
		ret = min(ret, cnt);
		_m[cnt] += 1;
		return;
	}
	
	
	// here - 1 // here + 1 // here * 2
	if(here - 1 >= 0)
		go(here - 1, cnt+1);
		
	if(here + 1 <= k)
		go(here + 1, cnt+1);
	
	if(here * 2 <= 2 * k)
		go(here * 2, cnt+1);
	
	
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	
	ret = abs(n-k);
	
	go(n, 0);
	
	cout << ret << "\n";
	cout << _m[ret];
	
	
}	

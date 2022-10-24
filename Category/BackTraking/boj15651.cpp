#include<bits/stdc++.h>
using namespace std;

int n, m, a[10];

void dfs(int cnt){
	if(cnt == m){
		for(int i = 0; i < m; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
		return;	
	}
	for(int i = 1; i <= n; i++){
		a[cnt] = i;
		dfs(cnt+1);
	}
	return;
}


int main(){
	cin >> n >> m;
	dfs(0);
}

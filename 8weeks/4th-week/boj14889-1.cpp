#include<bits/stdc++.h>
using namespace std;

int n, s[25][25], ret = 987654321;

int go(vector<int> &a, vector<int> &b){
	pair<int, int> p;
	
	for(int i = 0; i < n / 2; i++){
		for(int j = 0; j < n / 2; j++){
			if(i == j)
				continue;
				
			p.first += s[a[i]][a[j]];
			p.second += s[b[i]][b[j]];
		
		}
	}
	
	
	return abs(p.first - p.second);	
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> s[i][j];
		}
	}
	
	for(int i = 0; i < (1 << n); i++){
		int cnt = 0;
		for(int j = 0; j < n; j++){
			if(i & (1 << j))
				cnt++;	
		}
		
		if(cnt != n / 2)
			continue;
			
		vector<int> start, link;
		for(int j = 0; j < n; j++){
			if(i & (1 << j))
				start.push_back(j);
			else
				link.push_back(j);
		}
		
		ret = min(ret, go(start, link));	
	}
	
	cout << ret;
	return 0;
}

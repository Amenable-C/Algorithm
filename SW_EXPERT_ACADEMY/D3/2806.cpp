#include<bits/stdc++.h>
using namespace std;

int t, n, ret, y, x, a[15][15];
vector<pair<int, int>> v;

// ���� ������ y�� ��½��Ѿ� �ϰ�
// ���� ���� ������ x�� ��½��Ѿ���.


bool check(int y, int x){
	for(pair<int, int> i : v){
		// y üũ
		
		// x üũ
		if(i.second == x)
			return false;
		// �밢�� üũ
		if(abs(i.first - y) == abs(i.second - x))
			return false;
	}
	return true; 
}

void dfs(int y){
	if(y == n){ // �� ���� ��� 
		ret++;	
	}
	
	for(int i = 0; i < n; i++){
		if(check(y, i)){
			v.push_back({y, i});
			dfs(y + 1); 
			v.pop_back();
		}
		else{
			continue;
		}	
	}
}


int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		memset(a, 0, sizeof(a));
		ret = 0;
		cin >> n;
		// dfs�� Ǯ��� ��
		
		dfs(0);
		cout << "#" << i << " " << ret << "\n";		
	}
}

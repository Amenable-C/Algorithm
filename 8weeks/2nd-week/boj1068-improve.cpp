#include <bits/stdc++.h>
using namespace std;

int n, r, temp, root;
vector<int> adj[54];

int dfs(int here){
	int ret = 0; // ���� ����� �� 
	int child = 0;
	for(int there : adf[here]){
		if(there == r) // ©���� �κ� // �̷��� �� �� ������. 
			continue;
		ret += dfs(there); // �ڽ� ������ ���� ��带 �״� ��. 
		child++;
	}
	if(child == 0) // �� ������ ����� �� // �׷��ϱ� 1 
		return 1;
	return ret; // child�� �ִ� ��� // �ؿ��� ���� ������带 ��ģ ���� ���� �ø��� ��. 
}




int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp == -1)
			root = i; // 0�� �ִ´ٴ� ��.  
		else
			adj[temp].push_back(i); // ��Ʈ����� �� �ִ°�. // ��¥�� i���� ������ ���� �־ �̷��� �ִ°�. 
	}
	
	cin >> r;
	
	if(r == root){ // ������ 0�̱� ������ �̷��� ó�� 
		cout << 0 << "\n";
		return 0;	
	}
	
	cout << dfs(root) << "\n"; // ���⼭ ����� Ž�� // �ؿ������� �������� ���̱� ������ �ѹ��� �����Ѱ�. 
	return;
	
}

#include <bits/stdc++.h>
using namespace std;

int n, r, temp, root;
vector<int> adj[54];

int dfs(int here){
	int ret = 0; // 리프 노드의 수 
	int child = 0;
	for(int there : adf[here]){
		if(there == r) // 짤리는 부분 // 이러면 더 안 내려감. 
			continue;
		ret += dfs(there); // 자식 노드들의 리프 노드를 쌓는 것. 
		child++;
	}
	if(child == 0) // 맨 마지막 노드라는 것 // 그러니깐 1 
		return 1;
	return ret; // child가 있는 경우 // 밑에서 부터 리프노드를 합친 값을 위로 올리는 것. 
}




int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp == -1)
			root = i; // 0을 넣는다는 것.  
		else
			adj[temp].push_back(i); // 루트빼고는 다 넣는거. // 어짜피 i에서 순서가 돌고 있어서 이렇게 넣는것. 
	}
	
	cin >> r;
	
	if(r == root){ // 무조건 0이기 때문에 이렇게 처리 
		cout << 0 << "\n";
		return 0;	
	}
	
	cout << dfs(root) << "\n"; // 여기서 몇개인지 탐색 // 밑에서부터 차곡차곡 쌓이기 때문에 한번에 가능한거. 
	return;
	
}

#include<bits/stdc++.h>
using namespace std;

int n, m, k, t1, t2, t3;
long long t4;

long long sum(vector<long long> &tree, int i ){
	long long ans = 0;
	while(i > 0){
		ans += tree[i];
		i -= (i & -i); // 해당 인덱스에 최하위 인덱스를 빼주면 연결된 구간의 인덱스로 이동함. 
	}
	return ans;
}

void update(vector<long long> &tree, int i , long long diff){
	while(i < tree.size()){
		tree[i] += diff;
		i += (i & -i); // 해당 인덱스에 최하위 인덱스를 더하면 다음 인덱스로 이동 가능(영향을 끼치는 구간들임) 
	}
}


int main(){
	cin >> n >> m >> k;
	vector<long long> a(n + 1);
	vector<long long> tree(n + 1);
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		update(tree, i, a[i]); // 구간들로 나누어서 문제를 풀고 있음 -> 영향을 끼치는 구간에 입력 값들을 다 더해줘야 함. 
	}
	
	m += k;
	while(m--){
		cin >> t1;
		if(t1 == 1){ // 수를 바꾸는 경우.
			cin >> t2 >> t4;
			long long diff = t4 - a[t2];
			a[t2] = t4;
			update(tree, t2, diff); 
		}
		else{ // 합을 출력하는 경우. 
			int t2, t3;
			cin >> t2 >> t3;
			cout << sum(tree, t3) - sum(tree, t2 - 1) << "\n";
		}
	}
	return 0;
}

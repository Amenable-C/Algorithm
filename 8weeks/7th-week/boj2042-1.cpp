#include<bits/stdc++.h>
using namespace std;

int n, m, k, t1, t2;
long long t3;

void update(vector<long long> &tree, int idx, long long diff){
	while(idx < tree.size()){
		tree[idx] += diff;
		idx += (idx & -idx);
	}
	return;
}

long long sum(vector<long long> &tree, int idx){
	long long sum = 0;
	while(idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);	
	}
	return sum;
}


int main(){
	cin >> n >> m >> k;
	vector<long long> a(n + 1); // �� �ε����� �ش��ϴ� �� 
	vector<long long> tree(n + 1); // ���� Ʈ��
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		update(tree, i, a[i]);
	}
	
	m += k;
	while(m--){
		cin >> t1;
		if(t1 == 1){
			cin >> t2 >> t3;
			long long diff = t3 - a[t2];
			a[t2] = t3;
			update(tree, t2, diff);
		}
		else{
			cin >> t2 >> t3;
			cout << sum(tree, t3) - sum(tree, t2 - 1) << "\n";
		}
	}
	return 0;
}

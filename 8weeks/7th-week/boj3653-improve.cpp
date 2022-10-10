#include<bits/stdc++.h>
using namespace std;

int t, n, m, tree[200004], temp;
map<int, int> mp;

void update(int idx, int value){
	while(idx <= 200004){
		tree[idx] += value;
		idx += (idx & -idx);
	}
}

int sum(int idx){
	int ret = 0;
	while(idx > 0){
		ret += tree[idx];
		idx -= (idx & -idx);	
	}
	return ret;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while(t--){
		cin >> n >> m;
		memset(tree, 0, sizeof(tree));
		mp.clear();
		
		int update_idx = 100001; // ���� ������ ���ʿ� �δ°����� �ҷ��� �� // �迭������ -�� ����� �� �����Ƿ� �̵��ؾ� ��.  
		for(int i = 1; i <= n; i++){
			update(i + update_idx, 1); // �ڽ��� ������ �κп� ��� 1�� ������ => i�� �׿��ִٴ� ���� ��Ÿ���� ��. 
			mp[i] = i + update_idx;	// i��° cd�� ��ġ??? 
		}
		
		for(int i = 0; i < m; i++){
			cin >> temp; // �̵��� CD 
			int idx = mp[temp]; // ��ȭ ��ȣ�� �̿��Ͽ� �ش� ��ġ�� �˾Ƴ���. 
			cout << sum(idx) - 1 << " "; // �󸶳� �׿��ִ��� ��� // �ϴ� �ڱ� �ڽ� ����, ���ʿ� �ִ� �͵� ���ļ� ����ϴ� ��. 
			update(idx, -1); // �ش� CD�� �� ��� => �ش� ��ġ���� ������(�Ʒ�)�� -1 ���ֱ� (�׿��ִ� �ϳ��� �������� ���) 
			update(--update_idx, 1); // ���� �״� ��� // �ִ� 100001�� ��ŭ ����ؼ� ���� �� ���� // �̰� ������ ��ü�� ���������� �о �����Ѱ�. 
			mp[temp] = update_idx;	// �ش� ��ȭ ��ȣ�� �ش��ϴ� ��ġ�� �ٽ� map�� ����.  
		}
		cout << "\n";
	}
}

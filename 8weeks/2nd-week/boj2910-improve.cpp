#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int n, c, a[1004];

vector<pair<int, int>> v;
map<int, int> mp, mp_first;

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first){ // ī��Ʈ�� ���� ��� 
		return mp_first[a.second] < mp_first[b.second]; // '�ڿ����� �ʰ� �Դ�.' ��� �� 
	}
	return a.first > b.first;
}



int main(){
	cin >> n >> c;
	
	for(int i = 0; i < n; i++){
		cin >> a[i]; // �ش� ���� a[i]�� �ֱ� 
		mp[a[i]]++; // a[i]�� �ִ� �ش簪�� ��� counting�ϸ鼭 map�� ���� 
		
		if(mp_first[a[i]] == 0) // �̹� ������ �ش� ���� ���°� �ִ��� �ľ� 
			mp_first[a[i]] = i + 1; // �ش� ���� ���� ù��°�� ���Դ��� ����
	}
	
	for(auto it : mp){ // ī��Ʈ ������ �����ؾ� �ϹǷ� second�� value�� ���� 
		v.push_back({it.second, it.first}); // vector�� pair�� ���� ���� 
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(auto i : v){
		for(int j = 0; j < i.first; j++){
			cout << i.second << " ";	
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ret, temp;
stack<pair<ll, ll>> s;

int main(){
	cin >> n;
	for(int i = 0;  i < n; i++){
		cin >> temp;
		int cnt = 1; // cnt �ʱ�ȭ 
		while(s.size() && s.top().first <= temp){ // �ö󰡰ų� ���� ��� 
			ret += s.top().second; // �ٷ� ���� ����� ������ �� ���°�(�̹� cnt�� ���̰� ������ ����߱� ������ cnt�� �����ָ� ��) 
			if(s.top().first == temp){ // ���� ���� ���丮�� ��� 
				cnt = s.top().second + 1;
			}
			else{ // 
				cnt = 1;
			}
			s.pop();
		}
		
		if(s.size()) // �����ö� // �տ� �ִ� ����� �ڿ� ����� ������ �� �� �����Ƿ� cnt++; 
			ret++;
		
		s.push({temp, cnt});
	}
	
	cout << ret;
	return 0;
}

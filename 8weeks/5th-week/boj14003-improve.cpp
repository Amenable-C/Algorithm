#include<bits/stdc++.h>
using namespace std;

int n, lis[1000004], len, num;
pair<int, int> ans[1000004];
stack<int> stk;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		auto lowerPos = lower_bound(lis, lis + len, num);
		int _pos = (int)(lower_bound(lis, lis + len, num) - lis);
		
		if(*lowerPos == 0) // ���ε��� num�� ���� ū ��� 
			len++;
		
		*lowerPos = num; // lis�� ���� ���Խ�Ű�� �Ͱ� ����! // lower_bound�� 0�϶��� ������ ���Խ����ְ����� lower_bound�� 0�� �ƴ϶� ���Խ����ִ� ���� : �� �κп��� ���ο� lis�� ���� �� �ֱ� ���� 
		ans[i].first = _pos; // lower_bound�� idx ��ȣ 
		ans[i].second = num; // ���ε��� �� 
	}
	
	cout << len << "\n"; // �ִ� ���� 
	for(int i = n - 1; i >= 0; i--){
		if(ans[i].first == len - 1){
			stk.push(ans[i].second);
			len--;		
		}
	}
	while(stk.size()){
		cout << stk.top() << " ";
		stk.pop();
	}
	return 0;
}

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
		
		if(*lowerPos == 0) // 새로들어온 num이 가장 큰 경우 
			len++;
		
		*lowerPos = num; // lis에 값을 대입시키는 것과 같음! // lower_bound가 0일때는 무조건 대입시켜주겠지만 lower_bound가 0이 아니라도 대입시켜주는 이유 : 뒷 부분에서 새로운 lis를 만들 수 있기 때문 
		ans[i].first = _pos; // lower_bound의 idx 번호 
		ans[i].second = num; // 새로들어온 수 
	}
	
	cout << len << "\n"; // 최대 길이 
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

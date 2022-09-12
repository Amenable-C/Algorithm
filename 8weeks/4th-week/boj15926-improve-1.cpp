#include<bits/stdc++.h>
using namespace std;

int n, d[200001], ret, cnt;
string s;
stack<int> stk;

int main(){
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		if(s[i] == '(')
			stk.push(i);
		else if(stk.size()){ // ')'�� ��� 
			d[i] = d[stk.top()] = 1; // '�ش� ��ġ'�� '�ش� ��ġ�� ��Ī �Ǵ� ��'�� '1'�� �����ϴ°� 
			stk.pop();
		}
	}
	
	for(int i = 0; i < n; i++){
		if(d[i]){
			cnt++;
			ret = max(ret, cnt);
		}
		else
			cnt = 0;
	}
	
	cout << ret;
	return 0;
}

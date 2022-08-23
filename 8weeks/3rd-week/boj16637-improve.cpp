#include <bits/stdc++.h>
using namespace std;

vector<int> num;
vector<char> oper_str;
int n, ret = -987654321;
string s;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int oper(char a, int b, int c){
	if(a == '+')
		return b + c;
	if(a == '-')
		return b - c;
	if(a == '*')
		return b * c;	
}

void go(int here, int _num){ // here는 현재 위치 // _num은 누적합 
	if(here == num.size() - 1){ // 마지막일 경우 
		ret = max(ret, _num);
		return;
	}
	
	go(here + 1, oper(oper_str[here], _num, num[here + 1])); // 1 // 이게 가만히 있는거랑 같음. 
	
	if(here + 2 <= num.size() - 1){
		int temp = oper(oper_str[here + 1], num[here + 1], num[here + 2]);
		go(here + 2, oper(oper_str[here], _num, temp)); //2 // 이거는 순서를 바꾸어 주는거 
		// 1과 2가 각각 진행하면서 '마지막일 경우'에 각각 도착함. 어짜피 ret이 계속 업데이트 되어서 이렇게 하는거 
	}
	return;
}

int main(){
	fastIO();
	cin >> n;
	cin >> s;
		
	for(int i = 0; i < n; i++){
		if(i % 2 == 0) // 숫자인 경우 
			num.push_back(s[i] - '0');
		else // 연산자인 경우 
			oper_str.push_back(s[i]);	
	}
	
	go(0, num[0]);
	cout << ret;
	return 0;
}

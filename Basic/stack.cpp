#include <bits/stdc++.h>
using namespace std;



int main(){
	stack<string> stk;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stk.push("A");
	stk.push("B");
	stk.push("C");
	stk.push("D");
	stk.push("E");
	while(stk.size()){
		cout << stk.top() << endl;
		stk.pop();
	}
	cout << endl;
	
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.front() << endl;
	q.pop();
	cout << q.back() << endl;
	q.pop();
	
	cout << "size : " << q.size() << endl;
	
	deque<int> dq;
	dq.push_front(1);
	dq.push_back(2);
	dq.push_back(3);
	
	cout << dq.front() << endl;
	cout << dq.back() << endl;
	cout << dq.size() << endl;
	
	dq.pop_front();
	dq.pop_back();
	cout << dq.front() << endl;
	cout << dq.back() << endl;
	cout << dq.size() << endl;
	
	
	
	return 0;
}


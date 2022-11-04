#include<bits/stdc++.h>
using namespace std;

int n, m, cnt;
queue<int> q;

int main(){
	for(int _t = 1; _t <= 10; _t++){
		cnt = 0;
		cin >> n;
		
		for(int i = 0; i < 8; i++){
			cin >> n;
			q.push(n);
		}
		
		m = 1;
		while(true){
			if(m == 5)
				cnt++;
			
			n = q.front();
			q.pop();
			n = max(0, n - m);
			q.push(n);
			if(n == 0){
				break;
			}
			
			if(m + 1 > 5)
				m = (m + 1) / 5;
			else
				m++;
		}
		
		cout << "#" << _t << " ";
		for(int i = 0; i < 8; i++){
			cout << q.front() << " ";
			q.pop();
		}
		cout << "\n";
			
	}
	return 0;
}

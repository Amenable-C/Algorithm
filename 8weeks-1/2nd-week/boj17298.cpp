#include<bits/stdc++.h>
using namespace std;

int n, num, a[1000004];
stack<int> s;

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> num;
		a[i] = num;
		while(s.size() && a[s.top()] < num){
			a[s.top()] = num;
			s.pop();
		}
		
		s.push(i);
	}
	
	a[n-1] = -1;
	while(s.size()){
		a[s.top()] = -1;
		s.pop();	
	}
	
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";	
	}
	return 0;
}

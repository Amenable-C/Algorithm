#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int n, m, pre[MAX+4], visited[MAX+4];



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	
	if(n == m){
		cout << 0 << "\n" << n;
		return 0;	
	}
	
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	while(q.size()){
		int p = q.front();
		q.pop();

		for(int np : {p - 1, p + 1, p * 2}){
			if(0 <= np && np <= MAX){
				if(!visited[np]){
					visited[np] = visited[p] + 1;
					pre[np] = p;
					q.push(np);
				}
			}
		}
	}
	
	cout << visited[m] - 1 << "\n";
	stack<int> stk;
	long long pp = m;
	stk.push(pp);
	while(true){
		pp = pre[pp];
		stk.push(pp);
		if(pp == n)
			break;
	}
	while(stk.size()){
		int num = stk.top();
		cout << num << " ";
		stk.pop();	
	}
	return 0;
	
	
}

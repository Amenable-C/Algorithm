#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int visited[MAX+4];
long long cnt[MAX+4];
int before[MAX+4];


int n, k;

int main(){
	cin >> n >> k;
	
	if(n == k){
		cout << "0\n";
		cout << n;
		return 0;	
	}
	
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	cnt[n] = 1;
	
	while(q.size()){
		int now = q.front();
		q.pop();
		
		for(int next : {now - 1, now + 1, now * 2}){
			
			if(next >= 0 && next <= MAX){
				if(!visited[next]){
					visited[next] = visited[now] + 1;
					cnt[next] += cnt[now];
					before[next] = now;
					
					q.push(next);
				}else if(visited[next] == visited[now] + 1){
					cnt[next] += cnt[now];	
				}
			}
		}
	}
	
	cout << visited[k] - 1 << "\n";
	
	int target = k;
	stack<int> s;
	s.push(k);
	while(true){
		s.push(before[target]);
		target = before[target];
		
		if(target == n){
			break;
		}
	}
	
	while(s.size()){
		int num = s.top();
		cout << num << " ";
		s.pop();	
	}
	return 0;
	
}

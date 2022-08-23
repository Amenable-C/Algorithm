#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int visited[MAX+4];
long long cnt[MAX+4];
int n, k;


int main(){
	cin >> n >> k;
	if(n == k){
		cout << "0\n1";
		return 0;
	}
	
	queue<int> q;
	cnt[n] = 1;
	visited[n] = 1;
	q.push(n);
	while(q.size()){
		int now = q.front();
		q.pop();
		
		for(int next : {now - 1, now + 1, now * 2}){
			if(next >= 0 && next <= MAX){
				if(!visited[next]){
					visited[next] = visited[now] + 1;
					cnt[next] += cnt[now];
					q.push(next);
				}else if(visited[next] == visited[now] + 1){
					cnt[next] += cnt[now];	
				}
			}
		}
	}
	
	cout << visited[k] - 1<< "\n";
	cout << cnt[k];
	return 0;
	
}

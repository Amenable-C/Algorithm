#include<bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int dist[MAX+1];
long long cnt[MAX+1];

int main(){
	int n, m;
	cin >> n >> m;
	if(n == m){
		cout << 0 << "\n" << 1;
		return 0;
	}
	
	dist[n] = 0;
	cnt[n] = 1;
	queue<int> q;
	q.push(n);
	while(q.size()){
		int now = q.front();
		q.pop();
		
		for(int next : {now - 1, now + 1, now * 2}){
			if(0 <= next && next <= MAX){
				if(!dist[next]){
					q.push(next);
					dist[next] = dist[now] + 1;
					cnt[next] += cnt[now];
				}
				else if(dist[next] == dist[now] + 1){
					cnt[next] += cnt[now];	
				}
			}
		}
	}
	cout << dist[m] << "\n";
	cout << cnt[m];
	return 0;
}

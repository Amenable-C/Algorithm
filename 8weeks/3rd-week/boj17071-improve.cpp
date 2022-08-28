#include <bits/stdc++.h>
using namespace std;
const int max_n = 500000;
const int dx[3] = {-1, 1, 0};
const int dm[3] = {1, 1, 2};

int visited[2][500001], a, b, ok, turn = 1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b;
	
	if(a == b){
		cout << 0 << "\n";
		return 0;
	}
	
	queue<int> q;
	visited[0][a] = 1;
	q.push(a);
	
	while(q.size()){
		b += turn;
		if(b > max_n)
			break;
			
		if(visited[turn % 2][b]){ // 수빈이가 먼저 방문한 경우 
			ok = true;
			break;	
		}
		
		int qSize = q.size();
		for(int i = 0; i < qSize; i++){
			int x = q.front();
			q.pop();
			
			for(int j = 0; j < 3; j++){
				int nx = (x + dx[j]) * dm[j];
				if(nx < 0 || nx > max_n || visited[turn % 2][nx])
					continue;
				visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
				
				if(nx == b){ // 동생이 먼저와서 있는 경우 
					ok = 1;
					break;	
				}
				q.push(nx);
			}
		}
		if(ok)
			break;
		turn++;
	}
	if(ok)
		cout << turn << "\n";
	else
		cout << -1 << "\n";
	return 0;
	
}

#include<bits/stdc++.h>
using namespace std;

int n, k, visited[104], a[104], cnt, p;
vector<int> vec;

int main(){
	cin >> n >> k;
	
	for(int i = 0; i < k; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i < k; i++){
		if(!visited[a[i]]){ // 이미 꼽혀있으면 넘어가기 
			if(vec.size() == n){ // 꽉 차 있는 경우 // 하나를 빼줘야 함 
				int here = 0;
				for(int _a : vec){
					int there = 987654321;
					for(int j = i + 1; j < k; j++){
						if(a[j] == _a){
							there = j;
							break;
						}
					}
					
					
					if(there > here){
						here = there;
						p = _a;	
					}
				}
				
				visited[p] = 0;
				vec.erase(find(vec.begin(), vec.end(), p));
				cnt++;
			}
			
			vec.push_back(a[i]);
			visited[a[i]] = 1;
		}
	}
	cout << cnt;
	return 0;
}

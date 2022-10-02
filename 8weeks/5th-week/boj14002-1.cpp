#include<bits/stdc++.h>
using namespace std;

int n, a[1004], cnt[1004], prev_list[1004], ret, idx;
vector<int> v;

void go(int idx){
	if(idx == -1)
		return;
		
	v.push_back(a[idx]);
	go(prev_list[idx]);
	return;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	fill(cnt, cnt + 1004, 1);
	fill(prev_list, prev_list + 1004, -1);
	
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[i] > a[j] && cnt[i] <= cnt[j]){ 
				cnt[i] = cnt[j] + 1;
				prev_list[i] = j;
				
				if(cnt[i] > ret){
					ret = cnt[i];
					idx = i;
				}
			}
		}
	}
	
	go(idx);
	
	cout << ret << "\n";
	for(int i = v.size() - 1; i >= 0; i--){
		cout << v[i] << " ";
	}
	return 0;
	
}

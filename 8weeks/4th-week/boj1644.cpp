#include<bits/stdc++.h>
using namespace std;

int n, j = 2, a, b, ret;
bool check;
vector<pair<int, int>> vec;

int main(){
	cin >> n;
	
	if(n == 1){
		cout << 0;
		return 0;	
	}
	if(n == 2){
		cout << 1;
		return 0;	
	}
	
	vec.push_back({0, 0});
	vec.push_back({1, 2});
	for(int i = 3; i <= n; i++){
		check = true;
		for(int j = 2; j < i; j++){
			if(i % j == 0){
				check = false;
				break;
			}
		}
		
		if(check == true){
			vec.push_back({j++, vec.back().second + i});
		}
	}
	
	b = vec.size() - 1;
	
	for(int i = b; i > 0; i--){
		for(int j = 0; j < b; j++){
			if(vec[i].second - vec[j].second == n){
				ret++;	
			}
			else if(vec[i].second - vec[j].second < n)
				break;
		}
	}
	cout << ret;
	return 0;
}

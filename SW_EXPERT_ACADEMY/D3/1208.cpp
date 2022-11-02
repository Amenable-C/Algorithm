#include<bits/stdc++.h>
using namespace std;

int n, dump;
vector<int> v;

int main(){
	for(int i = 1; i <= 10; i++){
		cin >> dump;
		v.clear();
		for(int j = 0; j < 100; j++){
			cin >> n;
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		
		for(int j = 0; j < dump; j++){
			if(v[99] - v[0] == 0){
				break;
			}
			else if(v[99] - v[0] == 1){
				break;
			}
			
			v[0]++;
			v[99]--;
			sort(v.begin(), v.end());
		}
		
		cout << "#" << i << " " << v[99] - v[0] << "\n";
	}
	return 0;
}

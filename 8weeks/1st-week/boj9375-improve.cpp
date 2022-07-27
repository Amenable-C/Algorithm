#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n;
	
	string m_key, m_val;
	
	for(int i = 0; i < n; i++){
		map<string, int> nums;
		cin >> k;
		for(int j = 0; j < k; j++){
			cin >> m_val >> m_key;
			nums[m_key]++;
		}
		
		long long ret = 1;
		for(auto it : nums){
			ret *= (it.second + 1);
		}
		
		cout << ret - 1<< "\n";
	}
	
	return 0;	
	
}

#include <bits/stdc++.h>
using namespace std;

int t, n, num;
string nums;
char p[1000004];
string s;
vector<int> v;

int main(){
	cin >> t;
	while(t--){
		cin >> s;
		cin >> n;
		cin >> nums;	
		
		
		for(int i = 0; i < nums.size(); i++){
			if(nums[i] >= '0' && nums[i] <= '9'){
				num = num * 10 + (nums[i] - '0');
			}
			if(nums[i] == ',' || nums[i] == ']'){
				v.push_back(num);
				num = 0;	
			}
		}
		
		
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'R'){
				reverse(v.begin(), v.end());
			}
			else{ // 'D'
				if(v.size())
					v.erase(v.begin());
				else{
					break;
				}
			}
		}
		
		if(v.size()){
			cout << "[";
			while(v.size()){
				if(v.size() == 1){
					cout << v.front() << "]\n";
					v.erase(v.begin());
				}
				else{
					cout << v.front() << ",";
					v.erase(v.begin());
				}
			}
		}
		else{
			cout << "error\n";
		}
		
		v.clear();
	}
}

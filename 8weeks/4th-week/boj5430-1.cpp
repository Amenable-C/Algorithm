#include <bits/stdc++.h>
using namespace std;

int t, n, num;
bool rev = false;
string nums;
char p[1000004];
string s;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while(t--){
		rev = false;
		cin >> s >> n >> nums;
		
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
			if(s[i] == 'R')
				rev = !rev;
			else{ // 'D'
				if(v.size()){
					if(rev)
						v.pop_back();
					else
						v.erase(v.begin());
				}
				else{
					break;
				}
			}
		}
		if(rev)
			reverse(v.begin(), v.end());
		
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

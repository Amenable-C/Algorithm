#include <bits/stdc++.h>
using namespace std;

int a[104], len, m, num, c, zero_cnt;
string s, s_num;
map<int, int> mp;
vector<pair<int, int>> v;

int main(){
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> s;
		for(int i = 0; i < s.size(); i++){
			if(s[i] >= '0' && s[i] <= '9'){
				s_num += s[i];
				if(i < s.size() - 1)
					continue;
			}
			
			if(s_num.size() == 1){
				num = stoi(s_num);
				mp[num]++;
			}
			else if(s_num.size() > 1){
				while(s_num[c]){
					if(s_num[c] == '0'){
						zero_cnt++;
						c++;
						continue;
					}
					else
						break;
				}
				if(zero_cnt == s_num.size())
					num = 0;
				else{
					s_num = s_num.substr(zero_cnt);
					num = stoi(s_num);
				}
				mp[num]++;
			}	
			
			// 초기화 
			zero_cnt = 0;
			c = 0;
			s_num = "";
			
		}
				
		// 초기화
		s_num = ""; 
		c = 0;
		zero_cnt = 0;
	}
	
	if(mp.size()){
		for(auto it : mp){
			v.push_back({it.first, it.second});
		}
		
		sort(v.begin(), v.end());
		
		for(auto it : v){
			for(int i = 0; i < it.second; i++){
				if(it == v.back() && i == it.second - 1){
					cout << it.first;
				}
				else{
					cout << it.first << "\n";
				}
			}
		}
		
	}
	
	return 0;
}

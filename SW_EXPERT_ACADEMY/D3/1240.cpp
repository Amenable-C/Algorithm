#include<bits/stdc++.h>
using namespace std;

int t, n, m, nums, pos, flag, sum, ret, cnt, num;
string s, str, sub_s;

map<string, int> mp;

int main(){
	mp["0001101"] = 0;
	mp["0011001"] = 1;
	mp["0010011"] = 2;
	mp["0111101"] = 3;
	mp["0100011"] = 4;
	mp["0110001"] = 5;
	mp["0101111"] = 6;
	mp["0111011"] = 7;
	mp["0110111"] = 8;
	mp["0001011"] = 9;
	
	cin >> t;
	for(int _t = 1; _t <= t; _t++){
		flag = 0;
		cin >> n >> m;
		
		for(int i = 0; i < n; i++){
			cin >> str;
			if(str.find('1') != string::npos){
				s = str;
				flag = 1;
			}
		}
		
		if(flag == 0){
			cout << "#" << _t << " " << 0 << "\n";
			continue;		
		}
		
		for(int i = m - 1; i > 0; i--){
			if(s[i] == '1'){
				pos = i;
				break;
			}
		}
		
		ret = 0;
		cnt = 8;
		sum = 0;
		// 뒤에서 부터 출력 됨 
		for(int i = pos; i >= pos - 55; i -= 7){
			sub_s = s.substr(i - 6, 7);
			num = mp[sub_s];
			sum += num;
			if(cnt % 2 == 0){ // 짝수 자리 
				ret += num; 
			}
			else{ // 홀수 자리 
				ret += num * 3;
			}
			cnt--;
		}
		
		
		if(ret % 10 == 0){
			cout << "#" << _t << " " << sum << "\n";
		}
		else{
			cout << "#" << _t << " " << 0 << "\n";
		}
	}
}

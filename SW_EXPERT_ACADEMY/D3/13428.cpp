#include<bits/stdc++.h>
using namespace std;

int t, flag_max, flag_min;
string origin, sort_max, sort_min, _origin, s_max, s_min;


int main(){
	cin >> t;
	for(int _t = 1; _t <= t; _t++){
		flag_max = 0;
		flag_min = 0;
		cin >> origin;
		s_max = origin;
		s_min = origin;
		
		for(int i = 0; i < s_min.size(); i++){
			char c = s_min[i];
			if(i == 0){
				for(char f = '1'; f < c; f++){
					if(s_min.rfind(f) != string::npos && s_min.rfind(f) > i){
						s_min[i] = f;
						s_min[s_min.rfind(f)] = c;
						flag_min = 1;
						break;
					}
				}
				if(flag_min)
					break;
			}
			else{
				for(char f = '0'; f < c; f++){
					if(s_min.rfind(f) != string::npos && s_min.rfind(f) > i){
						s_min[i] = f;
						s_min[s_min.rfind(f)] = c;
						flag_min = 1;
						break;
					}
				}
				if(flag_min)
					break;
			}
		}
		
		for(int i = 0; i < s_max.size(); i++){
			char c = s_max[i];
			for(char f = '9'; f > c; f--){
				if(s_max.rfind(f) != string::npos && s_max.rfind(f) > i){
					s_max[i] = f;
					s_max[s_max.rfind(f)] = c;
					flag_max = 1;
					break;
				}
			}
			if(flag_max)
				break;
		}
		cout << "#" << _t << " " << s_min << " " << s_max << "\n";
	}
}

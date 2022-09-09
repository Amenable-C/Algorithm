#include<bits/stdc++.h>
using namespace std;
int T, n, num;
string p, l;
vector<int> v;
bool rev, error;


int main(){
	cin >> T;
	while(T--){
		rev = false;
		error = false;
		cin >> p >> n >> l;
		
		for(char c : l){
			if(c >= '0' && c <= '9'){
				num = num * 10 + (c - '0');	
			}
			if((c == ',' || c == ']') && num > 0){
				v.push_back(num);
				num = 0;	
			}
		}
		
		for(char c : p){
			if(c == 'R')
				rev = !rev;
			else{
				if(v.size()){
					if(rev)
						v.pop_back();
					else
						v.erase(v.begin());
				}
				else{
					error = 1;
				}
			}
		}
		
		if(error){
			cout << "error\n";
		}
		else if(n == 0){
			cout << "[]\n";	
		}
		else{
			if(rev)
				reverse(v.begin(), v.end());
				
			cout << "[";
			
			for(int i = 0; i < v.size(); i++){
				cout << v[i];
				if(i != v.size() - 1)
					cout << ",";
				else
					cout << "]\n"; 
			}
			
		}
		v.clear();		
	}
}

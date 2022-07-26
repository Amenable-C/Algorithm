#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int star = 0;
	
	while(s[star] != '*')
		star++;
	
	for(int i = 0; i < n; i++){
		string t;
		cin >> t;
		
		bool check = true;
		
		for(int j = 0; j < star; j++){
			if(s[j] != t[j]){
				check = false;
			}
		}
		
		for(int j = 1; j < s.size() - star; j++){
			if(s[-j] != t[-j]){
				check = false;
			}
			
		}
		
		if(t.size() <= star){
			cout << "NE" << endl;
			continue;
		}
		
		if(check)
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
			
	}	
}



#include <bits/stdc++.h>
using namespace std;
string s;
bool error = false;

int main(){
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'p'){
			if(i + 1 < s.size() && s[i+1] == 'i'){
				i = i + 1;	
			}
			else{
				error = true;
				break;
			}
		}
		else if(s[i] == 'k'){
			if(i + 1 < s.size() && s[i+1] == 'a')
				i = i + 1;
			else{
				error = true;	
				break;
			}
		}
		else if(s[i] == 'c'){
			if(i + 2 < s.size() && s[i+1] == 'h' && s[i+2] == 'u')
				i = i + 2;
			else{
				error = true;	
				break;
			}
		}
		else{
			error = true;
			break;
		}
	}
	
	if(error)
		cout << "NO";
	else
		cout << "YES";
	
	return 0;
}

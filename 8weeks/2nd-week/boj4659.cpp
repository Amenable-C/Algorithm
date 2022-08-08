#include <bits/stdc++.h>
using namespace std;

string s;
bool vowel = false;
bool overlap = false;
bool con_vow_overlap = false;
int con_count, vow_count;

int main(){
	cin >> s;
	
	while(s != "end"){
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
				vow_count++;
				con_count = 0;
				vowel = true;
			}
			else{
				con_count++;
				vow_count = 0;
			}
			
			if(i){
				if(s[i-1] == s[i] && s[i] != 'e' && s[i] != 'o'){
					overlap = true;
				}
				if(s[i-1] == s[i] && (s[i] == 'e' || s[i] == 'o')){
					con_count--;
				}
				
			}
			
			if(con_count >= 3 || vow_count >= 3)
				con_vow_overlap = true;
			
		}
		
		// 안되는 경우
		// vowel이 여전히 false인 경우 
		// overlap
//		cout << "con_vow_overlap : " << con_vow_overlap << ", vowel : " << vowel << ", overlap : " << overlap << endl;
		if(con_vow_overlap == true || vowel == false || overlap == true){
			cout << "<" << s << ">" << " is not acceptable." << "\n";
		}
		else{
			cout << "<" << s << ">" << " is acceptable." << "\n";
		}
	    
	    con_count = 0;
	    vow_count = 0;
	    con_vow_overlap = false;
		vowel = false;
		overlap = false;
		cin >> s;	
	}
}

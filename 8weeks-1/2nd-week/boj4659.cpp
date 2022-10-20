#include<bits/stdc++.h>
using namespace std;

string s;
int cnt[30], lcnt, vcnt;

bool isVowel(int idx){
	return (idx == 0 || idx == 4 || idx == 8 || idx == 14 || idx == 20);
}

int main(){
	while(true){
		cin >> s;
		if(s == "end")
			break;
			
		memset(cnt, 0, sizeof(cnt));
		lcnt = vcnt = 0;
		bool flag = 0;
		
		int prev = -1;
		
		for(int i = 0; i < s.size(); i++){
			int idx = s[i] - 'a';
			cnt[idx]++;
			if(isVowel(idx)){
				lcnt++;
				vcnt = 0;
			}
			else{
				vcnt++;
				lcnt = 0;	
			}
			
			if(vcnt == 3 || lcnt == 3)
				flag = 1;
			if(i >= 1 && (s[i - 1] == s[i]) && (idx != 4 && idx != 14))
				flag = 1;
		}
		
		if(!cnt[0] && !cnt[4] && !cnt[8] && !cnt[14] && !cnt[20])
			flag = 1;
		
		if(flag) cout << "<" << s << ">" << " is not acceptable.\n";
		else cout << "<" << s << ">" << " is acceptable.\n";
		
	}
}

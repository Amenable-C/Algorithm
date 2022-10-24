#include<bits/stdc++.h>
using namespace std;

int n, m, sum, cnt, idx, ret;
int check[51][4];
string s, ans;

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			if(s[j] == 'A')
				check[j][0]++;
			else if(s[j] == 'C')
				check[j][1]++;
			else if(s[j] == 'G')
				check[j][2]++;
			else if(s[j] == 'T')
				check[j][3]++;
		}
	}
	
	for(int i = 0; i < m; i++){
		cnt = 0;
		idx = 0;
		for(int j = 0; j < 4; j++){
			if(check[i][j] > cnt){
				cnt = check[i][j];
				idx = j;	
			}
		}
		if(idx == 0)
			ans += "A";
		else if(idx == 1)
			ans += "C";
		else if(idx == 2)
			ans += "G";
		else if(idx == 3)
			ans += "T";
			
		ret += (n - cnt);
	}
	cout << ans << "\n" << ret;
	return 0;
	
}

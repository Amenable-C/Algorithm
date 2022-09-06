#include <bits/stdc++.h>
using namespace std;

int n, m, words[51];
string s;

int count(int mask){
	int cnt = 0;
	for(int word : words){
		if(word && (word & mask) == word) // words[51]로 초기화 해놓아서 word가 있는지 체크도 해야함. 
			cnt++;
	}
	return cnt;
}


int go(int index, int k, int mask){
	if(k < 0) // 문장에 존재하는 단어의 개수가 k개를 초과한 경우 
		return 0;
	
	if(index == 26)
		return count(mask); 
		
	int ret = go(index + 1, k - 1, mask | (1 << index));
	
	if(index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a')
		ret = max(ret, go(index + 1, k, mask)); // 이거 자체가 a, n, t, i, c를 자동으로 넣고 비교까지 하는것 
	
	return ret;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(char str : s){
			words[i] |= (1 << (str - 'a'));	
		}
	}
	
	cout << go(0, m, 0);
	return 0;
}

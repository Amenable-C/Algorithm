#include <bits/stdc++.h>
using namespace std;

int k;
int visited[10];
char a[20];
vector<string> ret;

bool good(char x, char y, char op){
	if(x > y && op == '>')
		return true;
	if(x < y && op == '<')
		return true;
	
	return false;	
}

void go(int cnt, string num){
	if(cnt == k+1){
		ret.push_back(num);
		return;
	}
	
	for(int i = 0; i < 10; i++){
		if(visited[i])
			continue;
		
		if(cnt == 0 || good(num[cnt - 1], i + '0', a[cnt - 1])){
			visited[i] = 1;
			go(cnt + 1, num + to_string(i));
			visited[i] = 0;
		}
	}
	return;
}


int main(){
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> a[i];
	}
	
	go(0, "");
	sort(ret.begin(), ret.end());
	cout << ret[ret.size() - 1] << "\n" << ret[0];
	return 0;
}

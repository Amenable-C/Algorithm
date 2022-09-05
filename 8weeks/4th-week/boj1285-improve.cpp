#include <bits/stdc++.h>
using namespace std;

#define maxn 200005
typedef long long ll;

const int INF = 987654321;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int n, a[44], ret = INF;
string s;

void go(int here){
	if(here == n + 1){
		int sum = 0;
		for(int i = 1; i <= (1 << (n-1)); i *= 2){
			int cnt = 0;
			for(int j = 1; j <= n; j++) // 같은 열, 다른 행 // 즉 세로로 쭉 진행하는거. 
				if(a[j] & i)	
					cnt++;
			sum += min(cnt, n - cnt); // 일단 T를 다 카운트하고, min을 이용해서 뒤집기를 하는거. 
		}
		ret = min(ret, sum);
		return;
	}
	go(here + 1);
	a[here] = ~a[here];
	go(here + 1);
}


int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s;
		int value = 1;
		for(int j = 0; j < s.size(); j++){
			if(s[j] == 'T')
				a[i] |= value;
			value *= 2;
		}
	}
	
	go(1);
	cout << ret << "\n";
	return 0;
	
}

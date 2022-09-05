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
			for(int j = 1; j <= n; j++) // ���� ��, �ٸ� �� // �� ���η� �� �����ϴ°�. 
				if(a[j] & i)	
					cnt++;
			sum += min(cnt, n - cnt); // �ϴ� T�� �� ī��Ʈ�ϰ�, min�� �̿��ؼ� �����⸦ �ϴ°�. 
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

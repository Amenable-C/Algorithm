#include<bits/stdc++.h>
using namespace std;

int tot, m, n, sum_a[2003], sum_b[2003], a[1004], b[1004], sum;
map<int, int> a_cnt, b_cnt;

void make(int n, int psum[], map<int, int> &_map){
	for(int cnt = 1; cnt <= n; cnt++){
		for(int start = cnt; start <= n + cnt -1; start++){
				int _sum = psum[start] - psum[start - cnt];
				_map[_sum]++;
				if(cnt == n){
					break;
				}
		}	
	}
}

int main(){
	cin >> tot >> m >> n;
	
	for(int i = 1; i <= m; i++){
		cin >> a[i];
		sum_a[i] = sum_a[i-1] + a[i];
	}
	for(int i = m + 1; i < 2*m; i++){
		sum_a[i] = sum_a[i-1] + a[i - m];
	}
	
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		sum_b[i] = sum_b[i-1] + b[i];
	}
	for(int i = n + 1; i <= 2 * n; i++){
		sum_b[i] = sum_b[i-1] + b[i-n];	
	}
	
	make(m, sum_a, a_cnt);
	make(n, sum_b, b_cnt);
	
	for(int i = 1; i < tot; i++){
		sum += a_cnt[i] * b_cnt[tot-i];
	}
	
	sum += a_cnt[tot];
	sum += b_cnt[tot];
	
	cout << sum;
	return 0;
}

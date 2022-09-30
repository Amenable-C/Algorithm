#include<bits/stdc++.h>
using namespace std;

int want, n, m, temp, cnt;
int a[1001], b[1001], ret, aSum, bSum, psum_a[2002], psum_b[2002];
map<int, int> aCnt, bCnt;

// 피자 조각의 개수, 누적합, aCnt
void make(int n, int psum[], map<int, int> &_map){
	for(int interval = 1; interval <= n; interval++){ // 몇개의 조각으로 이루어지게 할 건지 결정. 
		for(int start = interval; start <= n + interval - 1; start++){ // 해당 조각들로 n번 만들기 // 원형으로 다 돌린다고 생각. 
			int sum = psum[start] - psum[start - interval];
			_map[sum]++; // 해당 경우의 수를 계속해서 더하기. 
			if(interval == n) // 모든 피자조각들을 다 사용할 경우 한번이므로 break 넣어주기. 
				break;
		}
	}
}


int main(){
	cin >> want >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		psum_a[i] = psum_a[i - 1] + a[i]; // 누적 합 
	}
	
	for(int i = n + 1; i < 2 * n; i++){
		psum_a[i] = psum_a[i - 1] + a[i - n]; // 원형인 것을 고려 
	}
	
	for(int i = 1; i <= m; i++){
		cin >> b[i];
		psum_b[i] = psum_b[i - 1] + b[i];	
	}
	
	for(int i = m + 1; i <= 2 * m; i++)
		psum_b[i] = psum_b[i - 1] + b[i - m];
		
	make(n, psum_a, aCnt);
	make(m, psum_b, bCnt);
	
	int sum = 0;
	
	for(int i = 1; i < want; i++){
		sum += aCnt[want - i] * bCnt[i]; // 가능한 조합 더하기 
	}
	
	// 각 피자들이 가능한 경우 고려 
	sum += aCnt[want];
	sum += bCnt[want];
	
	cout << sum;
	return 0;
}


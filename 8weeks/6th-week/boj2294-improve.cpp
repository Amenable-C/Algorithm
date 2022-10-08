#include<bits/stdc++.h>
using namespace std;

int n, k, a[10001], temp, INF = 987654321;

int main(){
	cin >> n >> k;
	fill(a, a + 10001, INF);
	a[0] = 0; // t라는 동전의 가치가 들어온 경우 t원이 1개의 t 동전으로 만들 수 있음을 의미하게 해줌. 
	
	for(int i = 0; i < n; i++){
		cin >> temp;
		for(int j = temp; j <= k; j++){
			a[j] = min(a[j], a[j - temp] + 1);	
		}
	}
	if(a[k] == INF)
		cout << -1;
	else
		cout << a[k];
	
	return 0;
	
	
}

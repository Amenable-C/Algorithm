#include<bits/stdc++.h>
using namespace std;

int n, m, ret = 1000000000, a[100004], lo, hi = 1000000000;

bool go(int mid){
	int cnt = 1;
	int money = mid;
	 
	for(int i = 0; i < n; i++){		
		if(money - a[i] >= 0){ // ���� ����� ���
			money -= a[i];
		}
		else{ // ���� ���ڸ��� ��� 
			cnt++;
			money = mid;
			money -= a[i];
		}
		if(cnt > m)
			return false; 
	}
	return true;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		lo = max(lo, a[i]);
	}
	
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		if(go(mid)){
			ret = min(ret, mid);
			hi = mid - 1;
		}
		else{
			lo = mid + 1;	
		}
	}
	
	cout << ret;
	return 0;
}

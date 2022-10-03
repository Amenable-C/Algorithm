#include<bits/stdc++.h>
#define max_n 60000000004
#define MAX_M 10004

using namespace std;
typedef long long ll;
ll n, m, a[MAX_M], lo, hi = max_n, ret, mid, temp; 

bool check(ll mid){
	temp = m; // 나눗셈의 몫으로 계산하거라서 처음에 m을 더해줘야 함. 
	for(ll i = 0; i < m; i++)
		temp += mid / a[i]; // mid라는 시간동안 해당 놀이기구가 몇번 운행될 수 있는지 계산 
	
	return temp >= n; // mid라는 시간 동안 n명 이상이 놀이기구를 탈 수 있으면 true 
}



int main(){
	cin >> n >> m; // n명, m종류의 1인승 놀이기구 
	for(ll i = 0; i < m; i++){
		cin >> a[i];
	}
	
	if(n <= m){ // 놀이기구가 충분한 경우 
		cout << n;
		return 0;	
	}
	
	while(lo <= hi){
		mid = (lo + hi) / 2;
		if(check(mid)){
			ret = mid;
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}
	
	// ret을 줄일 수 있을만큼 줄여놓아서 아래처럼 하면 적어도 한 명이 못 타는 경우 발생. 
	temp = m;
	for(ll i = 0; i < m; i++)
		temp += ((ret - 1) / a[i]);
	
		
	for(ll i = 0; i < m; i++){
		if(ret % a[i] == 0) // ret이라는 시간에 맞춰서 끝나는 놀이기구 // 위에서 (ret-1)을 이용할 떄 영향을 받은 것들 // 이렇게 하나씩 해야지 아이들이 순서대로 들어가고 제일 마지막에 들어갔을때 cout을 할 수 있음. 
			temp++;
		if(temp == n){
			cout << i + 1;
			return 0;	
		}
	}
	return 0;
}

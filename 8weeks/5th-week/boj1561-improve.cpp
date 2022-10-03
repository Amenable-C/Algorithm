#include<bits/stdc++.h>
#define max_n 60000000004
#define MAX_M 10004

using namespace std;
typedef long long ll;
ll n, m, a[MAX_M], lo, hi = max_n, ret, mid, temp; 

bool check(ll mid){
	temp = m; // �������� ������ ����ϰŶ� ó���� m�� ������� ��. 
	for(ll i = 0; i < m; i++)
		temp += mid / a[i]; // mid��� �ð����� �ش� ���̱ⱸ�� ��� ����� �� �ִ��� ��� 
	
	return temp >= n; // mid��� �ð� ���� n�� �̻��� ���̱ⱸ�� Ż �� ������ true 
}



int main(){
	cin >> n >> m; // n��, m������ 1�ν� ���̱ⱸ 
	for(ll i = 0; i < m; i++){
		cin >> a[i];
	}
	
	if(n <= m){ // ���̱ⱸ�� ����� ��� 
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
	
	// ret�� ���� �� ������ŭ �ٿ����Ƽ� �Ʒ�ó�� �ϸ� ��� �� ���� �� Ÿ�� ��� �߻�. 
	temp = m;
	for(ll i = 0; i < m; i++)
		temp += ((ret - 1) / a[i]);
	
		
	for(ll i = 0; i < m; i++){
		if(ret % a[i] == 0) // ret�̶�� �ð��� ���缭 ������ ���̱ⱸ // ������ (ret-1)�� �̿��� �� ������ ���� �͵� // �̷��� �ϳ��� �ؾ��� ���̵��� ������� ���� ���� �������� ������ cout�� �� �� ����. 
			temp++;
		if(temp == n){
			cout << i + 1;
			return 0;	
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n, len, num;
pair<int, int> a[100001];
int lis[100001];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;	
	}
	
	sort(a, a + n);
	
	for(int i = 0; i < n; i++){
		auto it = lower_bound(lis, lis + len, a[i].second);
		if(!(*it)) // �ڽ��� ���� ū ��� 
			len++; 
	
		*it = a[i].second; 

	}
	cout << n - len; // ���� ������ - �����־ �Ǵ� ������ = �����ؾ��ϴ� ������ 
	return 0;
}

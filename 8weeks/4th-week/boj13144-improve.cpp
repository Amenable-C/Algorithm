#include<bits/stdc++.h>
using namespace std;

long long s, e, cnt[100001], n, a[100001];
long long ret;

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];	
	}

	while(e < n){
		if(!cnt[a[e]]){ // ���� �ȿ� �ִ� ���� �ߺ��Ǵ� ���� ���� ��� 
			cnt[a[e]]++;
			e++;
		}
		else{ // ���⼭�� e�� �ٲ�°� �ƴ� s�� �ٲ�� �Ŷ� s�� �ߺ��� �������� ��� ������°�! 
			ret += (e - s);
			cnt[a[s]]--;
			s++;
		}
	}
	 
	ret += (e - s) * (e - s + 1) / 2;
	cout << ret;
	return 0; 
}

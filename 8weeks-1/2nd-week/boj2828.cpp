#include<bits/stdc++.h>
using namespace std;

int n, m, t, p, l, r, cnt;

int main(){
	cin >> n >> m >> t;
	
	l = 0;
	r = m;
	for(int i = 0; i < t; i++){
		cin >> p;
		if(p <= l){ // ���ʿ� �ִ� ��� 
			cnt += l - p + 1;
			l = p - 1;
			r = l + m;
			 
		}
		else if(p > r){ // �����ʿ� �ִ� ��� 
			cnt += p - r;
			r = p;
			l = p - m;
		}
	}
	cout << cnt;
	return 0;
}

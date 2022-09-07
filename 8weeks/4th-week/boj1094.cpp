#include<bits/stdc++.h>
using namespace std;
int x, cnt, m;


int main(){
	cin >> x;
	for(int i = 64; i > 0; i = i / 2){
		if(m + i <= x){
			m += i;
			cnt++;
		}
		
		if(m == x){
			cout << cnt;
			return 0;	
		}
	}
}

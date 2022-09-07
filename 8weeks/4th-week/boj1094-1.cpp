#include<bits/stdc++.h>
using namespace std;

int x, temp, cnt;

int main(){
	cin >> x;
	
	for(int i = 1; i <= (1<<6); i++){
		temp = 0;
		cnt = 0;
		for(int j = 0; j <= 6; j++){
			if(i & (1 << j)){
				temp += (1 << j);
				cnt++;
			}
		}
		if(x == temp){
			cout << cnt;
			return 0;	
		}
	}
}

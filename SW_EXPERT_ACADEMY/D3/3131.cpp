#include<bits/stdc++.h>
using namespace std;

bool prime[1000001] = {false, };

int main(){
	
	for(int i = 2; i <= 1000000; i++){
		if(!prime[i]){
			cout << i << " ";
			
			for(int j = i; j <= 1000000 ; j += i){
				prime[j] = true;
			}
		}
	}
	
	return 0;
}

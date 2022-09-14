#include<bits/stdc++.h>
using namespace std;

int n, a[2000001], p, lo, hi, ret, sum;
bool che[4000001];

int main(){
	cin >> n;
	
	for(int i = 2; i <= n; i++){
		if(che[i])
			continue;
		
		for(int j = i * 2; j <= n; j += i){
			che[j] = 1;
		}
	}
	
	for(int i = 2; i <= n; i++){
		if(!che[i])
			a[p++] = i;	
	}
	
	while(true){
		if(sum == n){
			ret++;
			sum -= a[lo++];	
		}
		else if(sum > n){
			sum -= a[lo++];	
		}
		else if(hi == p){
			break;	
		}		
		else{
			sum += a[hi++];
		}

	}
	
	cout << ret;
	return 0;
}

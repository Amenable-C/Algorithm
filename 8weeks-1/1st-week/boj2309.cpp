#include<bits/stdc++.h>
using namespace std;
int a[10], sum, _i, _j;

int main(){
	for(int i = 0; i < 9; i++){
		cin >> a[i];	
		sum += a[i];
	}

	sort(a, a + 9);
	for(int i = 0; i < 8; i++){
		for(int j = i + 1; j < 9; j++){
			if(sum - a[i] - a[j] == 100){
				_i = i;
				_j = j;	
			}
		}
	}
	
	for(int k = 0; k < 9; k++){
		if(k == _i || k == _j)
			continue;
		cout << a[k] << "\n";
	}
	
	return 0;
}

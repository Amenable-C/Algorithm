#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int a[9] = {};
	int sum = 0;
	for(int i = 0; i < 9; i++){
		cin >> a[i];
		sum = sum + a[i];
	}
	
	
	int j;
	int check;
	for(int i = 0; i < 9; i++){
		for(j = i + 1; j < 9; j++){
			check = sum;
			check = check - a[i] - a[j];
			if(check == 100)
				break;
		}
		
		if(check == 100){
			a[i] = 0;
			a[j] = 0;
			
			sort(a, a + 9);
			
			for(int k = 2; k < 9; k++)
				cout << a[k] << endl;
			
			break;
		}	
	}
	
	
	return 0;
	
}

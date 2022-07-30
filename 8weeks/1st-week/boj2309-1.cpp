#include <bits/stdc++.h>
using namespace std;

int a[9], sum;

int main(){
	for(int i = 0; i < 9; i++)
		cin >> a[i];
		
	sort(a, a+9);
	do{
		sum = 0;
		for(int i = 0; i < 7; i++)
			sum += a[i];
		if(sum == 100)
			break;
		
	}while(next_permutation(a, a + 9));
	
	for(int i = 0; i < 7; i++)
		cout << a[i] << "\n";	
		
	return 0;
}

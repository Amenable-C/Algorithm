#include <bits/stdc++.h>
using namespace std;

int t[104];
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	
	int d, e;
	
	for(int i = 0; i < 3; i++){
		cin >> d >> e;
		for(int k = d; d < e; d++)
			t[d]++;
	}	
	
	int sum = 0;
	for(int i = 0; i < 100; i++){
		if(t[i] == 1)
			sum += a * 1;
		else if(t[i] == 2)
			sum += b * 2;
		else if(t[i] == 3)
			sum += c * 3;
		else;
	}
	
	cout << sum;
		

	return 0;	
}

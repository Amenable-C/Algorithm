#include <bits/stdc++.h>
using namespace std;

int a, b, c, s, e;
int p[104];

int main(){
	cin >> a >> b >> c;
	for(int i = 0; i < 3; i++){
		cin >> s >> e;
		for(int j = s; j < e; j++){
			p[j]++;
		}
	}
	
	int sum = 0;
	for(int i = 0; i < 100; i++){
		if(p[i] == 1){
			sum += p[i] *  a * 1;
		}
		else if(p[i] == 2){
			sum += p[i] * b;
		}
		else if(p[i] == 3){
			sum += p[i] * c;
		}
		
	}
	
	cout << sum;
}

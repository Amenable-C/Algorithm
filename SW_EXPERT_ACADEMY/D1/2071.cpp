#include<bits/stdc++.h>
using namespace std;

int t, n;
double sum;

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		sum = 0;
		for(int j = 0; j < 10; j++){
			cin >> n;
			sum += n;
		}
		cout << "#" << i << " " << round(sum / 10.0) << "\n";
	}
	return 0;
}

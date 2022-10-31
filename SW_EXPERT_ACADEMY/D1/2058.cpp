#include<bits/stdc++.h>
using namespace std;

int n, sum;

int main(){
	cin >> n;
	while(true){
		sum += n % 10;
		if(!(n / 10)){
			break;
		}
		n /= 10;
	}
	cout << sum;
	return 0;
}

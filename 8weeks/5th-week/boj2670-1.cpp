#include<bits/stdc++.h>
using namespace std;

int n;
double a[10004], b, ret;

int main(){
	cin >> n;
	
	cin >> a[0];
	b = a[0];
	for(int i = 1; i < n; i++){
		cin >> a[i];
		if(a[i] > b * a[i]){
			b = a[i];
		}
		else{
			b *= a[i];
		}

		ret = max(ret, b);
	}
	
	printf("%.3lf", ret + 0.000001);
	return 0;
}

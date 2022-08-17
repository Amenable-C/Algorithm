#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[1000004];
int n, num;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		a[i] = num;	
	}
	
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] < a[j]){
				cout << a[j] << " ";
				break;
			}
			
			if(j == n - 1)
				cout << "-1 ";
		}
		if(i == n - 1)
			cout << "-1";
	}
}

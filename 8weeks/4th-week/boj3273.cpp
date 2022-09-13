#include<bits/stdc++.h>
using namespace std;

int n, x, ret;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
	
	cin >> n;
	
	long long a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	cin >> x;
	
	sort(a, a + n);
	
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j > 0; j--){
			if(i >= j)
				break;
			
			if(a[i] + a[j] == x){
				ret++;
				break;
			}
			else if(a[i] + a[j] < x)
				break;
		}
	}
	cout << ret;
	
}

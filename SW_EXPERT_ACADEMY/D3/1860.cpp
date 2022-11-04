#include<bits/stdc++.h>
using namespace std;

const int MAX = 11111;
int t, n, m, k, a[MAX + 4], b[MAX + 4], num, last, sum, flag;

int main(){
	cin >> t;
	for(int _t = 1; _t <= t; _t++){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		last = 0;
		sum = 0;
		flag = 0;
		
		cin >> n >> m >> k;
		
		for(int i = 0; i < n; i++){
			cin >> num;
			b[num]++;
			last = max(last, num);
		}
		
		
		for(int i = 1; i <= last; i++){
			if(i % m == 0){
				a[i] += a[i-1] + k;
			}
			else{
				a[i] += a[i-1];
			}
			
		}
		
		for(int i = 0; i <= last; i++){
			sum += b[i];
			if(sum > a[i]){
				flag = 1;
				break;
			}
		}
		
		cout << "#" << _t << " ";
		if(flag){
			cout << "Impossible\n";
		}
		else{
			cout << "Possible\n";
		}
	}
	return 0;
}

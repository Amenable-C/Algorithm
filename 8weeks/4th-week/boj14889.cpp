#include<bits/stdc++.h>
using namespace std;

int n, a[25][25], ret = 987654321;

vector<int> v1;
vector<int> v2;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];	
		}
	}
	
	int c[n];
	for(int i = 0; i < n; i++){
		c[i] = i;	
	}
	
	
	do{
		v1.clear();
		v2.clear();
		int sum1 = 0, sum2 = 0;
		for(int i = 0; i < n / 2; i++){
			v1.push_back(c[i]);
			v2.push_back(c[n - i - 1]);	
		}
		
		for(int _a : v1){
			for(int _b : v1){
				sum1 += a[_a][_b];
			}
		}
		
		for(int _a : v2){
			for(int _b : v2){
				sum2 += a[_a][_b];
			}
		}
		
		ret = min(ret, abs(sum1 - sum2));
	}while(next_permutation(c, c + n));
	
	cout << ret;
	return 0;
	
}

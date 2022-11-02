#include<bits/stdc++.h>
using namespace std;

int n, ret, flag;
char a[10][10];
string s;

int main(){
	for(int _t = 1; _t <= 10; _t++){
		ret = 0;
		
		cin >> n;
		for(int i = 0; i < 8; i++){
			cin >> s;
			for(int j = 0; j < 8; j++){
				a[i][j] = s[j];
			}
		}
		
		// üũ 
		for(int i = 0; i < 8; i++){
			for(int j = 0; j <= 8 - n; j++){
				flag = 0;
				for(int k = 0; k < n / 2; k++){
					if(a[i][j + k] != a[i][j + n - k - 1]){
						flag = 1;
					}
				}
				
				if(flag == 0)
				{
					ret++;	
				}
			}
		}
		
		for(int i = 0; i < 8; i++){
			for(int j = 0; j <= 8 - n; j++){
				flag = 0;
				for(int k = 0; k < n / 2; k++){
					if(a[j + k][i] != a[j + n - k - 1][i]){
						flag = 1;
					}
				}
				
				if(flag == 0)
				{
					ret++;	
				}
			}
		}
		
		cout << "#" << _t << " " << ret << "\n";
	}
	
}

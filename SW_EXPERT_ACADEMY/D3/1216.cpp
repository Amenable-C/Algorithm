#include<bits/stdc++.h>
using namespace std;

int n, cnt, ret, l, r, flag;
string s;
char a[104][104];

int main(){
	// 0 99, 0 98, 0 97, ... 0 1 // 1 99, 1 98, ... , 1 2 // ... // 98 99 => 한 열 또는 한 행
	// 위의 행위를 총  200번 하는거
	// 해당 짝에서 맞으면 계속 해서 +1 -1 하기 // 교차되면 cnt++
	
	for(int _t = 1; _t <= 10; _t++){
		cin >> n;
		ret = 0;
		
		for(int i = 0; i < 100; i++){
			cin >> s;
			for(int j = 0; j < 100; j++){
				a[i][j] = s[j];
			}			
		}
		
		for(int i = 0; i < 100; i++){
			for(int j = 0; j < 100; j++){
				for(int k = 99; k >= j; k--){
					l = j ;
					r = k;
					flag = 1;
					while(r > l){
						if(a[i][l] == a[i][r]){
							l++;
							r--;	
						}
						else{
							flag = 0;
							break;
						}
					}
					
					if(flag){
						ret = max(ret, k - j + 1);
					}
				}
			}
		}
		
		for(int i = 0; i < 100; i++){
			for(int j = 0; j < 100; j++){
				for(int k = 99; k >= j; k--){
					l = j;
					r = k;
					flag = 1;
					while(r > l){
						if(a[l][i] == a[r][i]){
							l++;
							r--;	
						}
						else{
							flag = 0;
							break;
						}
					}
					
					if(flag){
						ret = max(ret, k - j + 1);
					}
				}
			}
		}
		
		cout << "#" << _t << " " << ret << "\n";
	}
	 
	return 0;
}

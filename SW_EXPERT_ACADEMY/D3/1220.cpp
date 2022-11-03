#include<bits/stdc++.h>
using namespace std;

int n, a[104][104], cnt;
bool flag;

int main(){
	for(int _t = 1; _t <= 10; _t++){
		cin >> n;
		for(int i = 0; i < 100; i++){
			for(int j = 0; j < 100; j++){
				cin >> a[i][j];
			}
		}
		
		cnt = 0;
		
		for(int i = 0; i < 100; i++){
			flag = false;
			for(int j = 0; j < 100; j++){
				if(a[j][i] == 1){
					flag = true;	
				}
				else if(a[j][i] == 2 && flag == true){
					cnt++;	
					flag = false;
				}
			}
		}
			
		cout << "#" << _t << " " << cnt << "\n";
	}
	
	return 0;
}

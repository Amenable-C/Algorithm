#include<bits/stdc++.h>
using namespace std;

int h, w, num, a[104][104];
string s;
bool flag;

int main(){
	cin >> h >> w;
	for(int i = 0; i < h; i++){
		cin >> s;
		flag = 0;
		for(int j = 0; j < w; j++){
			if(s[j] == 'c'){
				flag = 1;
				num = 0;
			}
			if(flag == 0){
				a[i][j] = -1;
			}
			else{
				a[i][j] = num;
				num++;
			}
		}
	}
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

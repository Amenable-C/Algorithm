#include<bits/stdc++.h>
using namespace std;

int h, w, ret;
string a;
bool c_after;


int main(){
	cin >> h >> w;
	
	for(int i = 0; i < h; i++){
		cin >> a;
		for(int j = 0; j < w; j++){
			if(j == 0 && a[j] == 'c'){
				cout << "0" << " ";
				c_after = true;
				ret++;
				continue;
			}
			else if(j == 0 && a[j] == '.'){
				cout << "-1" << " ";
				continue;	
			}
			
			if(a[j] != 'c'){
				if(c_after){
					cout << ret << " ";
					ret++;	
				}
				else{
					cout << "-1" << " ";	
				}
				
			}
			else if(a[j] == 'c'){
				cout << "0" << " ";
				c_after = true;
				ret = 1;
			}
		}
		ret = 0;
		c_after = false;
	}

}

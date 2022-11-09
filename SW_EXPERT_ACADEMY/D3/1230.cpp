#include<bits/stdc++.h>
using namespace std;

int n, m, num, p, x, y;
char c;
vector<int> v;


int main(){
	for(int _t = 1; _t <= 10; _t++){
		v.clear();
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> num;
			v.push_back(num);
		}
		
		cin >> m;	
		for(int i = 0; i < m; i++){
			cin >> c;
			if(c == 'I'){
				cin >> x >> y;
				for(int j = 0; j < y; j++){
					cin >> num;
					// 위치 x에 num 넣기 // 넣으면서 x도 올려줘야 할듯	
					v.insert(v.begin() + x, num);
					x++;
					
				}
			}
			else if(c == 'D'){
				cin >> x >> y;
				// x의 위치 바로 다음부터 y개의 숫자 삭제 
				v.erase(v.begin() + x, v.begin() + x + y + 1);
			}
			else if(c == 'A'){
				cin >> y;
				for(int j = 0; j < y; j++){
					cin >> num;
					v.push_back(num);
				}
			}
		}
		
		cout << "#" << _t << " ";
		for(int i = 0; i < 10; i++){
			cout << v[i] << " ";	
		}
		cout << "\n";
	}
	return 0;
	
}

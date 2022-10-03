#include<bits/stdc++.h>
using namespace std;

int t, n , m, a[1000004], b[1000004], lo = 0, hi = 1000000;
bool flag = false;

int go(int mid, int b){
	if(a[mid] == b){
		return 0;	
	}
	else if(a[mid] > b){
		return 1;
	}
	else if(a[mid] < b){
		return -1;	
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		hi = n - 1;
		sort(a, a + n);
		
		cin >> m;
		for(int i = 0; i < m; i++){
			flag = 0;
			cin >> b[i];
			int l = lo;
			int h = hi;
			
			while(l <= h){
				int mid = (l + h) / 2;
				if(go(mid, b[i]) == 0){
					flag = true;
					break;
				}
				else if(go(mid, b[i]) < 0){
					l = mid + 1;
				}
				else if(go(mid, b[i]) > 0){
					h = mid - 1;
				}
			}
			
			if(flag){
				cout << 1 << "\n";
			}
			else{
				cout << 0 << "\n";	
			}
			
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
int a[15004];

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	//sort(a, a + n);
	if(m > 200000)
		cout << 0;
	else{
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				if(a[i] + a[j] == m)
					cnt++;		
		cout << cnt;
	}
	
	return 0;
}

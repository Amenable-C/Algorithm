#include<bits/stdc++.h>
using namespace std;

int t, n, m;

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n >> m;
		if(n > m)
			cout << "#" << i << " >\n";
		else if(n < m)
			cout << "#" << i << " <\n";
		else
			cout << "#" << i << " =\n";
	}
	return 0;
}

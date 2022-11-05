#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, ret;

int main(){
	for(int _t = 1; _t <= 10; _t++){
		cin >> n;
		cin >> n >> m;	
		ret = pow(n, m);
		cout << "#" << _t << " " << ret << "\n";
	}
}

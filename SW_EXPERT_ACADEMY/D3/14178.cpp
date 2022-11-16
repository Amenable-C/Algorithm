#include<iostream>
#include<memory.h>
using namespace std;

int t, n, d, a[300], cnt, p;

int main() {
	cin >> t;
	for (int _t = 1; _t <= t; _t++) {
		memset(a, 0, sizeof(a));
		cnt = 1;

		cin >> n >> d;
		
		p = d + 1;
		while(p + d < n) {
			cnt++;
			p = p + 2 * d + 1;
		}
		
		cout << "#" << _t << " " << cnt << "\n";
	}

	return 0;
}
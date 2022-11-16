#include<iostream>
#include<memory.h>
using namespace std;

int t, n, r, l, q, a[1004];

int main() {
	cin >> t;
	for (int _t = 1; _t <= t; _t++) {
		memset(a, 0, sizeof(a));

		cin >> n >> q;

		for (int i = 1; i <= q; i++) {
			cin >> l >> r;
			for (int j = l; j <= r; j++) {
				a[j] = i;
			}
		}

		cout << "#" << _t << " ";
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
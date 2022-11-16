#include<iostream>
using namespace std;

int l, u, x, t;


int main() {
	cin >> t;
	for (int _t = 1; _t <= t; _t++) {
		cin >> l >> u >> x;

		cout << "#" << _t << " ";
		if (l <= x && x <= u) {
			cout << "0";
		}
		else if (x < l) {
			cout << l - x;
		}
		else if (x > u) {
			cout << "-1";
		}
		cout << "\n";
	}
	return 0;
}
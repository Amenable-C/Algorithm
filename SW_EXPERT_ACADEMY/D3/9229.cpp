#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;
int t, n, m, a[1004], ret;


int main() {
	cin >> t;
	for (int _t = 1; _t <= t; _t++) {
		memset(a, 0, sizeof(a));
		ret = 0;

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] + a[j] > m)
					continue;
				ret = max(ret, a[i] + a[j]);
			}
		}

		cout << "#" << _t << " ";
		if (ret == 0) {
			cout << -1;
		}
		else {
			cout << ret;
		}
		cout << "\n";
	}
	return 0;
}
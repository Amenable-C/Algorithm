#include<iostream>
using namespace std;
int t, n, sum, ret, num;


int main() {
	cin >> t;
	for (int _t = 1; _t <= t; _t++) {
		ret = 0;
		cin >> n;
		for (int i = 1; i <= n / 2; i++) {
			num = i;
			sum = 0;
			while (sum < n) {
				sum += num;
				num++;
			}
			if (sum == n)
				ret++;
		}
		cout << "#" << _t << " " << ret + 1 << "\n";
	}
	return 0;
}
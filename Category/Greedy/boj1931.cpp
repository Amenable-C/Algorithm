#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, s, e, p, cnt;
vector<pair<int, int>> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		v.push_back({ e, s });
	}

	sort(v.begin(), v.end());

	for (pair<int, int> i : v) {
		if (i.second >= p) {
			cnt++;
			p = i.first;
		}
	}

	cout << cnt << "\n";
	return 0;
}
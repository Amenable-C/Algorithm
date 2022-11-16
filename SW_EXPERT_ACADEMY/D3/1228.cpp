#include <iostream>
#include <vector>

using namespace std;
int n, num, order, p, cnt;
char c;


int main() {
	for (int _t = 1; _t <= 10; _t++) {
		vector<int> v;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num;
			v.push_back(num);
		}

		cin >> order;
		for (int i = 0; i < order; i++) {
			cin >> c;
			cin >> p;
			cin >> cnt;
			for (int j = 0; j < cnt; j++) {
				cin >> num;
				v.insert(v.begin() + p, num);
				p++;
			}
		}

		cout << "#" << _t << " ";
		for (int i = 0; i < 10; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
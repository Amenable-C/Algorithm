#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long ll;
ll n, m, v, k, c, ret;



int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n >> k;
	vector<pair<ll, ll>> v(n);
	vector<ll> bag(k);

	for (ll i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (ll i = 0; i < k; i++) {
		cin >> bag[i];
	}

	sort(v.begin(), v.end());
	sort(bag.begin(), bag.end());

	ll p = 0;
	priority_queue<ll> pq;

	for (ll i : bag) {
		while (p < n && v[p].first <= i) {
			pq.push(v[p].second);
			p++;
		}

		if (pq.size()) {
			ret += pq.top();
			pq.pop();
		}
	}

	cout << ret << "\n";
	return 0;
}
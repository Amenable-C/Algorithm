#include<iostream>
#include<string>
#include<map>
#include<string.h>
using namespace std;
int t, n, a[14];
string s;
map<string, int> mp;
map<int, string> mpOut;

int main() {
	mp["ZRO"] = 0;
	mp["ONE"] = 1;
	mp["TWO"] = 2;
	mp["THR"] = 3;
	mp["FOR"] = 4;
	mp["FIV"] = 5;
	mp["SIX"] = 6;
	mp["SVN"] = 7;
	mp["EGT"] = 8;
	mp["NIN"] = 9;

	mpOut[0] = "ZRO";
	mpOut[1] = "ONE";
	mpOut[2] = "TWO";
	mpOut[3] = "THR";
	mpOut[4] = "FOR";
	mpOut[5] = "FIV";
	mpOut[6] = "SIX";
	mpOut[7] = "SVN";
	mpOut[8] = "EGT";
	mpOut[9] = "NIN";

	cin >> t;
	for (int _t = 1; _t <= t; _t++) {
		memset(a, 0, sizeof(a));
		cin >> s;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s;
			a[mp[s]]++;
		}

		cout << "#" << _t << "\n";
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < a[i]; j++) {
				cout << mpOut[i] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}
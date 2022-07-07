#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int b[5];
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}

int main(){
	for(int i = 5; i >= 1; i--)
		b[i-1] = i;
	for(int i = 5; i >= 1; i--)
		a.push_back(i);

	// 오름차순	
	sort(b, b+5);
	sort(a.begin(), a.end());

	for(int i : b)
		cout << i << " ";
	cout << endl;
	
	for(int i : a)
		cout << i << " ";
	cout << endl;
	
	// 내림차순
	sort(b, b+5, greater<int>());
	sort(a.begin(), a.end(), greater<int>());

	for(int i : b)
		cout << i << " ";
	cout << endl;
	
	for(int i : a)
		cout << i << " ";
	cout << endl;
	
	// vector v
	for(int i = 10; i >= 1; i--)
		v.push_back({i, 10-i});
	
	//sort(v.begin(), v.end(), cmp); // 응? 
	for(auto it : v)
		cout << it.first << " : " << it.second << endl;
	
	return 0;
}

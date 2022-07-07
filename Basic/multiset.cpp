#include <bits/stdc++.h>
using namespace std;

multiset<int> s;

int main(){
	s.insert(12);
	s.insert(10);
	s.insert(2);
	s.insert(10);
	s.insert(90);
	s.insert(85);
	s.insert(45);
	
	cout << "Multiset elements after sort\n";
	for(auto it = s.begin(); it != s.end(); it++)
		cout << *it << ' ';
	cout << endl;
	
	auto it1 = s.find(10);
	auto it2 = s.find(90);
	s.erase(it1, it2);
	
	cout << "Multiset elements after erase\n";
	for(auto it = s.begin(); it != s.end(); it++)
		cout << *it << ' ';
	cout << endl;
	
	s.erase(s.begin());
	for(auto it = s.begin(); it != s.end(); it++)
		cout << *it << ' ';
	cout << endl;
	
	return 0;
}


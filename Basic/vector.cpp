#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main(){
	for(int i = 1; i <= 10; i++)
		v.push_back(i);
	for(int a : v)
		cout << a << " ";
	cout << endl;
	
	v.pop_back();
		
	for(int a : v)
		cout << a << " ";
	cout << endl;
	
	v.erase(v.begin(), v.begin() + 1);
	for(int a : v)
		cout << a << " ";
	cout << endl;
		
	auto a = find(v.begin(), v.end(), 100);
	if(a == v.end())
		cout << "not found" << endl;
	
	fill(v.begin(), v.end(), 10);
	for(int a : v)
		cout << a << " ";
	cout << endl;
	
	v.clear();
	for(int a : v)
		cout << a << " "; // none
	cout << endl; 
	
	// 크기를 5로 설정하고 100으로 채우기 
	vector<int> v1(5, 100);
	for(int a : v1)
		cout << a << " ";
	cout << endl;
}


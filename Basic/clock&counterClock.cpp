#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int main(){
	for(int i = 1; i < 10; ++i)
		v.push_back(i);
		
	rotate(v.begin(), v.begin() + v.size() - 1, v.end()); // 시계 방향 
	//rotate(v.begin(), v.begin() + 1, v.end()); // 반시계 방향 
	
	for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		cout << ' ' << *it;
		
	cout << endl;
	
}

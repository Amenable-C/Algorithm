#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int main(){
	for(int i = 1; i < 10; ++i)
		v.push_back(i);
		
	rotate(v.begin(), v.begin() + v.size() - 1, v.end()); // �ð� ���� 
	//rotate(v.begin(), v.begin() + 1, v.end()); // �ݽð� ���� 
	
	for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		cout << ' ' << *it;
		
	cout << endl;
	
}

#include<bits/stdc++.h>
using namespace std;

int n;
char a, b, c;
pair<int, int> v[30];

void preOrder(int root){
	int left = v[root].first;
	int right = v[root].second;
	
	cout << (char)(root + 'A');
	
	if(left > 0)
		preOrder(left);
	if(right > 0)
		preOrder(right);
}

void inOrder(int root){
	int left = v[root].first;
	int right = v[root].second;
	
	if(left > 0)
		inOrder(left);
		
	cout << (char)(root + 'A');		
	
	if(right > 0)
		inOrder(right);
}

void postOrder(int root){
	int left = v[root].first;
	int right = v[root].second;
	
	if(left > 0)
		postOrder(left);
	if(right > 0)
		postOrder(right);
	cout << (char)(root + 'A');	
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c;
		v[a - 'A'] = make_pair(b - 'A', c - 'A');
	}
	
	preOrder(0);
	cout << "\n";
	
	inOrder(0);
	cout << "\n";
	
	postOrder(0);
}

#include<bits/stdc++.h>
using namespace std;

int n;
float score;
priority_queue<float, vector<float>, greater<float>> pq;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> score;
		pq.push(score);
	}
	
	for(int i = 0; i < 7; i++){
		printf("%.3f\n", pq.top());
		pq.pop();	
	}
	return 0;
	
}

#include<bits/stdc++.h>
using namespace std;

int a, b, c, s, e, cnt[104], sum;

int main(){
	cin >> a >> b >> c;
	
	for(int i = 0; i < 3; i++){
		cin >> s >> e;
		for(int j = s; j < e; j++)
			cnt[j]++;
	}
	
	for(int i = 0; i < 100; i++){
		if(cnt[i] == 1){
			sum += a;
		}
		else if(cnt[i] == 2){
			sum += 2 * b;
		}
		else if(cnt[i] == 3){
			sum += 3 * c;
		}
	}
	cout << sum;
	return 0;
}

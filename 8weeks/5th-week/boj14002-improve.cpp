#include<bits/stdc++.h>
using namespace std;

int n, a[1001], ret = 1, cnt[1001], idx;
int prev_list[1001];
vector<int> _real;

void go(int idx){
	if(idx == -1)
		return;
	_real.push_back(a[idx]);
	go(prev_list[idx]);
	return;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	fill(prev_list, prev_list + 1001, -1);
	fill(cnt, cnt + 1001, 1);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[j] < a[i] && cnt[i] <= cnt[j]){ // 1�� �ʱ�ȭ�� �س��Ƽ� ���� ��쵵 ����ؾ���. 
				cnt[i] = cnt[j] + 1;
				prev_list[i] = j;
				if(ret < cnt[i]){ // maxValue �����ϴ°� 
					ret = cnt[i];
					idx = i;
				}
			}
		}
	}
	
	cout << ret << "\n";
	go(idx);
	for(int i = _real.size() - 1; i >= 0; i--){
		cout << _real[i] << " ";
	}
	return 0;
}

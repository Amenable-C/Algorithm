#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
vector<pi> chs;
vector<pi> homes;
vector<vector<int>>chickenList;

int n, m, num;
int each;
int a[54][54];
int tot=1000000;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void combi(int start, vector<int> v){
	if(v.size() == m){ // �ϼ��� m���� chickenList�� �ִ°�. // ������ �־����. 
		chickenList.push_back(v);
		return;
	}
	for(int i = start + 1; i < chs.size(); i++){
		v.push_back(i);
		combi(i, v);
		v.pop_back();	
	}
	
}


int main(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			
			if(a[i][j] == 1){
				homes.push_back(pi(i, j));	
			}
			else if(a[i][j] == 2){
				chs.push_back(pi(i, j));
				
			}
		}
	}
	
	
	// ch m�� �̰�, home �� �Ÿ� �� ���ϱ� // �ߺ����͵� ���� ����� ����. -> �ð����⵵���� ���� combi �־����!!
	vector<int> v;
	combi(-1, v); // �ѹ濡 ���� �� �ִ� combi�� ��ü ���� 
	
	for(vector<int> cList : chickenList){
		each = 0;
		for(int i = 0; i < homes.size(); i++){
			int dis = 300; 
			for(int ch : cList){
				dis = min(abs(homes[i].first - chs[ch].first) + abs(homes[i].second - chs[ch].second), dis);
				
			}
			each += dis;
		}
		tot = min(tot, each);
	}
		 
	cout << tot;
}

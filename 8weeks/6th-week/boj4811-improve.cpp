#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, dp[31][31];

ll go(int whole, int not_whole){
	if(whole == 0 && not_whole == 0)
		return 1; // go(1 - 1, 0), go(0, 1 - 1)�̶�� ���� ��ü�� 1�� ���� ����. 
	if(dp[whole][not_whole]) // �̹� �Դ� ���̸� ���ο� ���� �� �̻� ��ô(?)���� �ʴ� �� => ret�� �������� ����!!!
		return dp[whole][not_whole];
	
	// ������ ���� �������� �Ѵ� == ���� �ִ� ���� �������� �Ѵ�.  
	ll &ret = dp[whole][not_whole];
	if(whole > 0)
		ret += go(whole - 1, not_whole + 1);
	if(not_whole > 0)
		ret += go(whole, not_whole - 1);
	return ret;
}

int main(){
	while(true){
		cin >> n;
		if(n == 0)
			break;
		cout << go(n, 0) << "\n";
	}
	return 0;
}
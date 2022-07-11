#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> v;
	int a[5] = {1, 2, 2, 2, 3};
	for(int i = 0; i < 5; i++){
		v.push_back(a[i]);
	}
	
	int x = 2;
	int c = (int)(upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x)); // x의 개수 확인
	int f = (int)(lower_bound(v.begin(), v.end(), x) - v.begin()); // 시작되는 점의 값
	int t = (int)(upper_bound(v.begin(), v.end(), x) - v.begin());
	
	int f2 = *lower_bound(v.begin(), v.end(), x);
	int t2 = *upper_bound(v.begin(), v.end(), x);
	 
	printf("%d의 개수 : %d, 시작되는 점 : %d 끝나는 점 : %d\n", x, c, f, t);
	printf("lower boiund가 시작되는 점의 값 : %d, upper bound가 시작되는 점의 값 : %d\n", f2, t2);
	
	c = (int)(upper_bound(a, a + 5, x) - lower_bound(a, a + 5, x));
	f = (int)(lower_bound(a, a + 5, x) - a);
	t = (int)(upper_bound(a, a + 5, x) - a);
	f2 = *lower_bound(a, a + 5, x);
	t2 = *upper_bound(a, a + 5, x);
	 
	printf("%d의 개수 : %d, 시작되는 점 : %d 끝나는 점 : %d\n", x, c, f, t);
	printf("lower boiund가 시작되는 점의 값 : %d, upper bound가 시작되는 점의 값 : %d\n", f2, t2);
	
	return 0; 
	
}

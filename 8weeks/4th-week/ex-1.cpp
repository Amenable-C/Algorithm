#include <bits/stdc++.h>
using namespace std;

void t1(){
	int n = 15; // 1111
	int idx = 0;
	n &= ~(1 << idx);
	cout << "1. idx��° ��Ʈ������ : " << n << "\n"; 
}

void t2(){
	int n = 5; // 0101
	int idx = 3;
	n ^= (1 << idx);
	cout << "2. 0�� 1��, 1�� 0���� XOR T2 : " << n << "\n";
	
}

void t3(){
	int n = 6; // 110
	int idx = (n & -n);
	cout << "3. ������ �����ִ� �ε��� T3: " << idx << "\n"; 
}

void t4(){
	int n = 4;
	cout << "4. ũ�Ⱑ n�� ��� ������ ��� ��Ʈ �ѱ� T4 : " << (1<<n) - 1<< "\n"; 
}

void t5(){
	int n = 8;
	int idx = 2;
	n |= (1 << idx);
	cout << "5. idx��° ���ѱ� T5 : " << n << "\n"; 
}

void t6(){
	int n = 15; // 1111
	int idx = 0;
	string a = n & (1 << idx) ? "yes" : "no";
	cout << "6. idx��° ��Ʈ�� �ִ��� Ȯ���ϱ� T6 : " << a << "\n"; 
}



int main(){
	t1();
	t2();
	t3();	
	t4();
	t5();
	t6();
	return 0;
}

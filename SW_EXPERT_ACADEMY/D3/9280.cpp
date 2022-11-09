#include<bits/stdc++.h>
using namespace std;

int t, n, m, carAndParking[2004], num, cost;

//map<int, int> parkingPosition;





int main(){
	cin >> t;
	for(int _t = 1; _t <= t; _t++){
		cost = 0;
		memset(carAndParking, 0, sizeof(carAndParking));
		
		map<int, int> parkingCost;
		map<int, int> carWeight;
		map<int, pair<int, int>> carTime;
		queue<int> waitedCar;
		priority_queue<int, vector<int>, greater<int>> parkingLots;
		
		cin >> n >> m;
		
		// ������ �ֱ�
		for(int i = 1; i <= n; i++)
			parkingLots.push(i); 
		
		for(int i = 1; i <= n; i++){
			cin >> num;
			parkingCost[i] = num;
		}
		for(int i = 1; i <= m; i++){
			cin >> num;
			carWeight[i] = num;	
		}
		
		for(int i = 0; i < 2 * m; i++){
			cin >> num;
			if(num > 0){ // �����°� 
				// pq �ִ� ��� �ٷ� �ֱ� -> ��ġ, �ð� ������Ʈ 
				if(parkingLots.size()){
					carAndParking[num] = parkingLots.top();
					parkingLots.pop();
					carTime[num] = {i, 0};
				} else { // pq ���°�� watied�� �ױ� 
					waitedCar.push(num);
				}
			} 
			else { // �����°� 
				// pq ���ְ� -> �ð� ������Ʈ
				num = -num;
				carTime[num] = {carTime[num].first, i};
				
				int parkingLot = carAndParking[num];
				parkingLots.push(parkingLot);
				
				if(waitedCar.size()){ // waited�ִ°� ������ �ϳ� �־��ֱ� -> ��ġ, �ð� ������Ʈ 
					int carNum = waitedCar.front();
					waitedCar.pop();
					
					carAndParking[carNum] = parkingLot;
					parkingLots.pop();
					carTime[carNum] = {i, 0};
				}
			}				
		}
		
		// ��� ������ ��� 
		for(int i = 1; i <= m; i++){
			cost += parkingCost[carAndParking[i]] * carWeight[i];
		}
		
		// ��� 
		cout << "#" << _t << " " << cost << "\n";
	}
}

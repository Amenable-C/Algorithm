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
		
		// 주차장 넣기
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
			if(num > 0){ // 들어오는거 
				// pq 있는 경우 바로 넣기 -> 위치, 시간 업데이트 
				if(parkingLots.size()){
					carAndParking[num] = parkingLots.top();
					parkingLots.pop();
					carTime[num] = {i, 0};
				} else { // pq 없는경우 watied에 쌓기 
					waitedCar.push(num);
				}
			} 
			else { // 나가는거 
				// pq 빼주고 -> 시간 업데이트
				num = -num;
				carTime[num] = {carTime[num].first, i};
				
				int parkingLot = carAndParking[num];
				parkingLots.push(parkingLot);
				
				if(waitedCar.size()){ // waited있는거 있으면 하나 넣어주기 -> 위치, 시간 업데이트 
					int carNum = waitedCar.front();
					waitedCar.pop();
					
					carAndParking[carNum] = parkingLot;
					parkingLots.pop();
					carTime[carNum] = {i, 0};
				}
			}				
		}
		
		// 모든 차량들 계산 
		for(int i = 1; i <= m; i++){
			cost += parkingCost[carAndParking[i]] * carWeight[i];
		}
		
		// 출력 
		cout << "#" << _t << " " << cost << "\n";
	}
}

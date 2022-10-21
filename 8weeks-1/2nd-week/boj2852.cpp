#include<bits/stdc++.h>
using namespace std;

int t, team1, team2, now_time, prev_time, goal_time, team, m, s, team1_time, team2_time;

int main(){
	cin >> t;
	t--;
	scanf("%d %d:%d", &team, &m, &s);
	prev_time = m * 60 + s;
	if(team == 1){
		team1++;	
	}
	else{
		team2++;	
	}
	
	while(t--){
		scanf("%d %d:%d", &team, &m, &s);
		now_time = m * 60 + s;
		goal_time = now_time - prev_time;
		prev_time = now_time;
		if(team1 > team2){
			team1_time += goal_time;
		}
		else if(team1 < team2){
			team2_time += goal_time;
		}
		
		if(team == 1){
			team1++;	
		}
		else{
			team2++;	
		}
	}
	
	now_time = 48 * 60;
	goal_time = now_time - prev_time;
	if(team1 > team2){
		team1_time += goal_time;
	}
	else if(team1 < team2){
		team2_time += goal_time;
	}
	printf("%02d:%02d\n", team1_time / 60, team1_time % 60);
	printf("%02d:%02d", team2_time / 60, team2_time % 60);
	return 0;
}

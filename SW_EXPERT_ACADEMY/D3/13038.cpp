#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;

int t, n, week_lecture, a[20], week, day, day_ret, ret;

int main() {
	cin >> t;
	for (int _t = 1; _t <= t; _t++) {
		memset(a, 0, sizeof(a));
		week_lecture = 0;
		day_ret = 10;

		cin >> n;
		for (int i = 0; i < 7; i++) {
			cin >> a[i];
			if (a[i])
				week_lecture++;

			a[i + 7] = a[i];
		}

		week = n / week_lecture;
		day = n % week_lecture;
		if (day == 0) {
			week--;
			day = week_lecture;
		}
			

		if(week){
			for (int i = 0; i < 7; i++) {
				int day_cnt = 0;
				int lecture_cnt = 0;
				for (int j = i + 1; j < i + 8; j++) {
					day_cnt++;
					if (a[j])
						lecture_cnt++;

					if (lecture_cnt == day)
						break;
				}

				day_ret = min(day_ret, day_cnt);
			}
		}
		else {
			for (int i = 0; i < 7; i++) {
				if (!a[i])
					continue;

				int day_cnt = 0;
				int lecture_cnt = 0;
				for (int j = i; j < i + 7; j++) {
					day_cnt++;
					if (a[j])
						lecture_cnt++;

					if (lecture_cnt == day)
						break;
				}
				cout << day_ret << "\n";
				day_ret = min(day_ret, day_cnt);
			}
		}

		ret = week * 7 + day_ret;
		cout << "#" << _t << " " << ret << "\n";
	}
	return 0;
}
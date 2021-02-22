#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second == b.second ? a.first < b.first : a.second < b.second;
	//return a.second < b.second;
}

int main() {

	//입력
	int N; //회의 최대 개수
	cin >> N;

	vector<pair <int, int>> meeting;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		meeting.push_back({ start, end });
	}

	//종료 시간 빠른 순 -> 시작 시간 빠른 순
	sort(meeting.begin(), meeting.end(), compare);

	int ans = 1;
	int end = meeting[0].second; //처음 시작점
	for (int i = 1; i < meeting.size(); i++) { //2번째 회의부터
		if (meeting[i].first >= end) {
			ans++;
			end = meeting[i].second;
		}
	}

	cout << ans;

	return 0;
}
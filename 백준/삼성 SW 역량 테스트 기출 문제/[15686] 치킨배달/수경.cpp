//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M; //N(가로, 세로), M(최대 집수 )
int map[51][51];
vector<tuple<int, int>> chicken;
vector<tuple<int, int>> house;

int getCityDist(vector<tuple<int, int>> chickenList) {

	int cityDist = 0;
	for (int i = 0; i < house.size(); i++) {
		int minDist = 100000;
		for (int j = 0; j < chickenList.size(); j++) {
			int dist = abs(get<0>(house[i]) - get<0>(chickenList[j])) + abs(get<1>(house[i]) - get<1>(chickenList[j]));
			minDist = min(minDist, dist);
		}
		cityDist += minDist;
	}

	return cityDist;
}


int main() {

	//freopen("input4.txt", "r", stdin);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) chicken.push_back({ i, j });
			if (map[i][j] == 1) house.push_back({ i, j });
		}
	}

	//조합.
	vector<int> combi;
	for (int i = 0; i < chicken.size() - M; i++) combi.push_back(0);
	for (int i = 0; i < M; i++) combi.push_back(1);

	sort(combi.begin(), combi.end());

	int answer = 100000;
	do {

		vector<tuple<int, int>> tmp;
		for (int i = 0; i < combi.size(); i++) 
			if (combi[i] == 1) tmp.push_back(chicken[i]);

		answer = min(answer, getCityDist(tmp)); //뽑힌 m개의 치킨집에 대해 "도시치킨거리" 

	} while (next_permutation(combi.begin(), combi.end()));

	cout << answer << '\n';
	
	return 0;
}

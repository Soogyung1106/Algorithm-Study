#include <string>
#include <vector>
#include <utility>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	vector <pair<int, int>> on_bridge; // <트럭 무게, 남은 길이>
	int weightSum = 0;
	int time = 0;

	while ((truck_weights.size() > 0) || (on_bridge.size() > 0)) 
    {
		time++;
		weightSum = 0;

		//다리 위 트럭들의 무게 계산
		for (int i = 0; i < on_bridge.size(); i++) 
        { 
			weightSum += on_bridge[i].first;
		}
        //다리의 하중보다 여유가 있고, 남은 트럭이 있으면
		if ((truck_weights.size() > 0) && (weightSum + truck_weights.front() <= weight))
        { 
			on_bridge.push_back(make_pair(truck_weights.front(), bridge_length));
			truck_weights.erase(truck_weights.begin());
		}

		//다리 위 트럭들의 남은 거리 감소
		for (int i = 0; i < on_bridge.size(); i++) 
        { 
			on_bridge[i].second--;
		}

		//도착한 트럭 제외
		while ((on_bridge.size() > 0) && (on_bridge.front().second <= 0))
        {
            on_bridge.erase(on_bridge.begin());
        }
	}
	return time + 1; // 마지막 트럭이 다리에서 건너편으로 이동할 때 +1
}

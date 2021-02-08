#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    queue<pair<int, int>> bridge; //(트럭무게, 다리에 진입한 시간)
    int cur_weight = 0; //현재 다리에 올라와 있는 무게 
    
    reverse(truck_weights.begin(), truck_weights.end());
    
    while(1){ 
        time++; //시간 경과
        
        //트럭을 뺄 경우 
        if(time - bridge.front().second == bridge_length){
            cur_weight -= bridge.front().first;  //갱신
            bridge.pop(); //경과된 시간 - 트럭이 투입된 시간 = 즉, 다리 길이만큼의 시간 
        }
        
        
        //트럭을 투입 
        if(truck_weights.back() + cur_weight <= weight){
            //종료 조건
            if(truck_weights.size() == 1) return time + bridge_length; 
            
            pair<int, int> p = make_pair(truck_weights.back(), time);
            bridge.push(p);
            
            //갱신
            cur_weight += truck_weights.back();
            truck_weights.pop_back(); 
        }
    }
    
}

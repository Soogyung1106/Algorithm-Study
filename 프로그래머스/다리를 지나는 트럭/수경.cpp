#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    queue<int> t; //트럭이 다리에 올라간 시간 차례로 삽입.
    queue<int> bridge; //다리에 올라와 있는 트럭의 무게 차례로 삽입.
    int time = 0; 
    int t_idx = 0; //truck_weights를 가리키는 인덱스 
    int sum =0; //다리에 올라와 있는 무게
    
    while(1){
        time++;
        
        //빼야 할 시간이 되면
        if(time - t.front() == bridge_length){ 
            sum -= bridge.front();
            bridge.pop();
            t.pop();
        }
        
        //무게를 견딜 수 있다면
        if(truck_weights[t_idx]+sum <= weight){ 
            
            if(t_idx == truck_weights.size()-1){ //종료조건
                return time + bridge_length;
            }
            
            sum += truck_weights[t_idx];
            t.push(time); //다리에 올라간 시간
            bridge.push(truck_weights[t_idx]); //다리에 올리기
            t_idx++;
        }
        
    }
    
}

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    
    //timetable 분 단위로 바꾸기
    deque<int> waiting;
    for(auto s : timetable){
        int time = 0;
        string tmp = s.substr(0, 2);
        time += stoi(tmp)*60;
        tmp = s.substr(3, 2); 
        time += stoi(tmp);
        waiting.push_back(time);
    }
  
    //오름차순 정렬
    sort(waiting.begin(), waiting.end());
    
    //9:00부터 셔틀 운행 시작. 
    int shuttle_time = 540-t; 
    int int_answer = 0;
    for(int i =0;i<n;i++){ //i번째 셔틀 운행.
        shuttle_time += t;
        int can_sit = m; //shuttle_time에 태울 수 있는 승객 수.
        
        deque<int> tmp; //탑승 가능한 승객들.
        while(!waiting.empty()){ 
            if(waiting.front() <= shuttle_time){ //탈 수 있는 조건
                tmp.push_back(waiting.front());
                waiting.pop_front();
                can_sit--;
                if(can_sit == 0) break; //종료조건: 꽉 찼을 경우..
            }else break;   
        }    
        
        //마지막 자리라면..?
        if(i == n-1){
            //앉을 자리가 없다면..
            if(can_sit == 0) int_answer = tmp.back()-1;
            //앉을 자리가 있다면..
            else int_answer = shuttle_time;          
        }  
    }
    
    //분을 00:00 string 포맷으로 바꾸기 
    string answer = "";
    int hour = int_answer/60;
    int minute = int_answer%60;
    
    if(hour<10) answer += '0'+ to_string(hour);
    else answer += to_string(hour);
    
    answer += ':';
    if(minute<10) answer += '0'+ to_string(minute);
    else answer += to_string(minute);
    
    return answer;
}

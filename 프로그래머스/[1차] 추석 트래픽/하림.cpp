//
//  main.cpp
//  test
//
//  Created by 정하림 on 2021/05/02.
//

#include <iostream>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//vector<string> lines = {"2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"};

vector<string> lines = {"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"};


int solution(vector<string> lines) {
    int answer = 0;
    int count = 0;
    vector<double> start_time, end_time;
    vector<int> overlap;
    
    /*
        날짜는 고정 2016-09-15
        뒤의 hh mm ss.sss를 판별해야함
        이후 처리시간이 들어가는데 처리시간은 최대 소숫점 셋째 자리까지 기록하며 처리시간 뒤에는 s가 붙음
        처리시간은 최대 3초
        lines 배열은 완료시간을 기준으로 오름차순 되어있음
        
        임의의 1초간 처리하는 요청의 최대 갯수를 구하여라
        
        */
        
    
    for(int i=0; i<lines.size(); i++){
        double h,m,s,T;
        h = stod(lines[i].substr(11,2));
        m = stod(lines[i].substr(14,2));
        s = stod(lines[i].substr(17,6));
        T = stod(lines[i].substr(24,lines[i].length()-24-1));
        // T(처리시간) 을 구하기 위해 문자열의 24번째 부터 맨 끝 문자열 한칸 전까지 string을 나눠줌
        start_time.push_back((h*3600)+ (m*60) + s - T + 0.001);
        end_time.push_back((h*3600)+ (m*60) + s);
    }
    
    for(int i=0; i<lines.size(); i++) {
        for(int j= i; j<lines.size(); j++){
            if(start_time[j]<end_time[i]+1){
                count++;
            }
        }
        if(answer < count){
            answer = count;
        }
        count = 0;
    }
    
    return answer;
}


int main(void) {
    cout << solution(lines) << endl;
    return 0;
}

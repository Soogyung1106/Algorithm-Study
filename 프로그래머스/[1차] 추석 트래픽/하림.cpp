//
//  하림.cpp
//  test
//
//  Created by 정하림 on 2021/05/02.
//

#include <iostream>

#include <string>
#include <vector>
#include <iostream>

using namespace std;


int solution(vector<string> lines) {
    int answer = 0;
    int count = 0;
    vector<double> start_time, end_time;
    
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
        for(int j=i; j<lines.size(); j++){
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

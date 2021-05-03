#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<string> lines) {
    
    //시작 시간, 종료시간
    vector<pair<double, double>> v;
    for(auto line : lines){
        string tmp = line.substr(24);
        double processing = stod(tmp.substr(0, line.size()-1));
        double end = stod(line.substr(11, 2))*3600 + stod(line.substr(14, 2))*60 + stod(line.substr(17, 6));
        double start = end - processing + 0.001; //응답 시작 시간 = 응답 완료 시간 - 처리시간 + 0.001
        v.push_back({start, end});
    }

 
    int answer = 0;
    for(int i = 0; i < v.size(); i++) {
        double start = v[i].first;
        double end = v[i].second;
        int cnt = 1;

        for(int j = i + 1; j < v.size(); j++) {
            if(start+1 >= v[j].first || end+1 > v[j].first) 
                cnt++;
        }
        answer = max(answer, cnt);
    }

    return answer;
}

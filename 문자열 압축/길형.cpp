#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    for(int i = 1; i <= s.size()/2 ;i++) // 비교할 단어의 길이
    {
        string temp = s.substr(0,i); // string s의 s[0:i] 슬라이싱
        int count = 1; // 압축된 단어의 개수
        int temp_size = 0;
        
        for(int j = i; j < s.size() ;j += temp.size()) // temp와 비교 s[i]부터 temp만큼++
        {
            if(temp == s.substr(j,i)) // 압축할 단어 발견 O
            {
                count++;
            }
            else // 압축할 단어 발견 X -> 다음 단어 설정 후 Ntemp(N>0)의 size() 반환
            {
                if(count == 1) temp_size += temp.size(); // 압축 X -> temp 길이 그대로
                else temp_size += to_string(count).size() + temp.size(); // N(N>0)과 temp의 길이
                
                temp = s.substr(j,i); // index = j,size = i 크기의 비교 단어 설정
                count = 1; // 압축 단어를 찾았으니 다시 count = 1부터 초기화
            }
        }
        /* 남은 문자열 s.size()%i != 0 인 경우 */
        if(count == 1) temp_size += temp.size(); 
        else temp_size += to_string(count).size() + temp.size();
        
        answer = temp_size < answer ? temp_size : answer;
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0,0};
    string front,back;

    for(int i=1 ; i < words.size() ; i++)
    {
        front = words[i-1];
        back = words[i];

        if(front[front.size()-1] != back[0]) // n-1의 마지막 알파벳과 n의 첫번째 알파벳 비교
        {

            answer[0] = (i%n)+1;
            answer[1] = (i/n)+1;
            return answer;
        }
        else
        {
            for(int j = 0 ; j<i ; j++)
            {
                if(words[i] == words[j]) // 중복되는 단어 확인
                {
                    answer[0] = (i%n)+1;
                    answer[1] = (i/n)+1;
                    return answer;
                }
            }
        }
    }
}

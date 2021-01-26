#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) 
{
    // 조건문 하나로 만들 수 있지만, 가독성을 위해 하나의 조건문에 모두 담지 않아습니다.
    for(int i = 0 ; i < new_id.size() ; i++) // 대문자 검사
    {
        if(new_id[i] >= 'A' && new_id[i] <= 'Z')
        {
            new_id[i] = tolower(new_id[i]);
        }
    }
    
    for(int i = 0 ; i < new_id.size() ; i++) // 2단계 소문자, 숫자, 특정 문자 제외 제거
    {
        if(new_id[i] < 'a' || new_id[i] > 'z') // 알파벳 소문자가 아니라면
        {
            if(new_id[i] < '0' || new_id[i] > '9') // 숫자가 아니라면
            {
                if(new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.') // 지정된 특수문자가 아니라면 ' ' 변환
                {
                    new_id[i] = ' ';
                }
            }
        }
    }
    
    new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end()); // 변환된 ' ' 제거
    
    for(int i = 0 ; i < new_id.size() ; i++) // 3단계 연속되는 '.' 제거
    {
        if(new_id[i] == '.')
        {
            if(i != new_id.size()-1) // '.'이 마지막 인덱스에 있으면 메모리 범위 오류
            {
                int j = i+1;
                int count = 0;
                
                while(new_id[j] == '.')
                {
                    count++;
                    j++;
                }
                
                new_id.erase(i+1, count);
            }
        }
    }
    
    if(new_id[0] == '.') new_id[0] = ' '; // 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거
    if(new_id[new_id.size()-1] == '.') new_id[new_id.size()-1] = ' ';
    
    new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end()); // 변환된 ' ' 제거
    
    if(new_id.empty()) new_id = "a"; // 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입
    
    if(new_id.size() >= 16) // 6단계 new_id의 길이가 16자 이상이면, 그 뒤에꺼 다 제거
    {
        new_id.erase(15);
        if(new_id[14] == '.') new_id.erase(14);
    }
    
    if(new_id.size() < 3) // 7단계 new_id의 길이가 2자 이하라면
    {
        char last = new_id[new_id.size()-1];
        new_id.append(3 - new_id.size(), last);
    }
    
    return new_id;
}

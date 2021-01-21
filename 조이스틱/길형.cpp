#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int sum = 0;
    int index = 0;
    int count = 1;
    int r = 0, l = 0;
    vector<int> check(name.size(), 0);
    
    
    for(int i = 0 ; i < name.size() ; i++) // 위, 아래 알파벳 맞추기 저장.
    {
        if(name[i] != 'A')
        {
            int a = name[i] - 'A' ;
            int b = ('Z' - name[i]) + 1;
            answer += min(a,b);
        }

    }
    
    for(int i = 0 ; i < name.size() ; i++) // A이면 안가도 됨.
    {
        if(name[i] != 'A')
        {
            check[i] = 1;
            ++sum;
        }
    }
    
    if(sum == 0) return 0;
    else if(sum == name.size()) return answer + sum -1;
    
    while(sum != 1)
    {
        if(check[index]) // name[i]가 A가 아니여서 check[i]에 마킹한거라면..
        {
            sum--;
            check[index] = 0;
        }
        
        for(int i = 1 ; i < check.size() ; i++)
        {
            r = check.size() - (index + i);
            l = index + i;

            if(check[r % check.size()] && check[l % check.size()]) // ABAAB같은 경우
            {
                // dfs를 써야할거 같은데...그리디니까...다른거로
                index = r % check.size();
                answer += i;
            }
            if(check[r % check.size()] && !check[l % check.size()])
            {
                index = r % check.size();
                answer += i;
            }
            if(!check[r % check.size()] && check[l % check.size()])
            {
                index = l % check.size();
                answer += i;
            }
        }
    }

    
    return answer;
}

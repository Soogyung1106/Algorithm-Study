#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int num = 0;
    
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(num < 0) return false;
        if(s[i] == '(') num++;
        else if(s[i] == ')') num--;
    }
    
    if(num != 0) return false;
    else return true;
}

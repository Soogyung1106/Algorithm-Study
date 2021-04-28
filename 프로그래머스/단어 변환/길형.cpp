#include <string>
#include <vector>
#define MAX 51

using namespace std;

int answer = 987654321;
string tar;
bool check[MAX];

void dfs(string begin, vector<string> &words, int result)
{
    if(tar == begin)
    {
        answer = min(answer,result);
        return ;
    }
    
    for(int i = 0 ; i < words.size() ; i++)
    {
        int count = 0;
        
        for(int j = 0 ; j < words[i].size();j++)
        {
            if(begin[j] != words[i][j]) count++;
            if(count == 2) break;
        }
        if(count == 1)
        {
            if(!check[i])
            {
                check[i] = true;
                dfs(words[i], words, result +1);
                check[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    tar = target;
    dfs(begin,words,0);
    
    if(answer == 987654321) answer = 0;
    
    return answer;
}

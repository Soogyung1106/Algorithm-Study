#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
IDEA : ' '을 이용하여 자른다. => for(auto a: str) 이용하면 더 쉽게 할 수 있다. 모범답안 참고

4차원 배열을 이용하여 언어, 직군, 경력, 음식으로 배열을 나눈다.
언어는 3개, 직군은 2개, 경력 2개, 음식 2개



*/

vector<int> database[3][2][2][2]; // 언어, 직무, 경력, 음식

vector<string> split_q(string str)
{
    vector<string> v;
    string temp;
    
    for(char ch: str)
    {
        if(ch == ' ')
        {
            v.push_back(temp);
            temp = "";
        }
        else temp += ch;
    }
    
    v.push_back(temp); // 마지막엔 ' '가 안나옴
    
    return v;
}

vector<int> split_i(string str)
{
    vector<int> v;
    string temp;
    int n;
    
    for(char ch: str)
    {
        if(ch == ' ')
        {
            if(temp == "cpp" || temp == "backend" || temp == "junior" || temp == "chicken") n = 0;
        else if(temp == "java" || temp == "frontend" || temp == "senior" || temp == "pizza") n = 1;
        else if(temp == "python") n = 2;
        
        v.push_back(n); //index 정하기
        temp = "";
        }
        else temp += ch;
    }

    v.push_back(stoi(temp)); // 마지막에 코테 점수
    
    return v;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(string s: info) // 처음에 주어진 info 쪼개서 인덱스에 넣기
    {
        vector<int> v = split_i(s); // split_i 쪼개고-분류-index
        database[v[0]][v[1]][v[2]][v[3]].push_back(v[4]);
    }
    
    for(int i = 0 ; i < 3 ; i++)
        for(int j = 0 ; j < 2 ; j++)
            for(int k = 0 ; k < 2 ; k++)
                for(int l = 0 ; l < 2 ; l++)
                    sort(database[i][j][k][l].begin(), database[i][j][k][l].end());
    
    for(string s: query)
    {
        vector<string> v = split_q(s);
        
        // 쿼리 조건에 따른 구간 정의
        int ai,bi,aj,bj,ak,bk,al,bl;

        if(v[0]=="cpp") ai=bi=0;
        else if(v[0]=="java") ai=bi=1;
        else if(v[0]=="python") ai=bi=2;
        else {ai=0; bi=2;} // '-'

        if(v[2]=="backend") aj=bj=0;
        else if(v[2]=="frontend") aj=bj=1;
        else {aj=0; bj=1;}; // '-'

        if(v[4]=="junior") ak=bk=0;
        else if(v[4]=="senior") ak=bk=1;
        else {ak=0; bk=1;} // '-'

        if(v[6]=="chicken") al=bl=0;
        else if(v[6]=="pizza") al=bl=1;
        else {al=0; bl=1;} // '-'

        int score = stoi(v[7]);

        // 점수가 X점 이상인 사람의 수 계산
        int ans=0;
        for(int i=ai; i<=bi; i++){
          for(int j=aj; j<=bj; j++){
            for(int k=ak; k<=bk; k++){
              for(int l=al; l<=bl; l++){
                int n = database[i][j][k][l].size();
                if(n==0) continue;

                // 이분 탐색
                auto iter = lower_bound(database[i][j][k][l].begin(),database[i][j][k][l].end(),score);

                if(iter == database[i][j][k][l].end()) continue;
                ans += n-(iter-database[i][j][k][l].begin());
              }
            }
          }
        }
        answer.push_back(ans);
      }
    
    return answer;
}

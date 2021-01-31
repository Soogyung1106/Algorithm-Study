#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

void num_str(string &str, vector<long long> &nums, vector<char> &ops)
{
    long long num = 0;
    
    for(int i = 0; i < str.size() ; i++)
    {
        if(str[i] >= '0') // 숫자
        {
            num *= 10; // 자리수 증가 1 -> 10 -> 100 -> ...
            num += str[i] - '0'; // ASCII -> string 변환
        }
        else // 연산자
        {
            nums.push_back(num);
            ops.push_back(str[i]);
            
            num = 0;
        }
    }
    
    nums.push_back(num);
}

long long calculate(long long num1, long long num2, char op)
{
    if (op == '+')
    { 
        return num1 + num2; 
    } 
    else if (op == '-') 
    { 
        return num1 - num2; 
    } 
    else if (op == '*') 
    { 
        return num1 * num2; 
    } 
    
    return -1;
}

long long solution(string expression) { 
    // 숫자 배열과 연산자 배열 만들기 
    vector<long long> nums;
    vector<char> ops;
    
    num_str(expression, nums, ops);
    
    string op_order = "+-*";
    sort(op_order.begin(), op_order.end()); // 3개 연산자의 순열을 위한 문자열 생성 후 정렬
    
    long long answer = 0;
    
    do 
    { 
        /* 숫자열과 연산자열을 q1에 저장. q2는 1차례 계산 후의 숫자열과 연산자열이 저장될 큐 */ 
        queue<long long, deque<long long>> num_q2, num_q1(deque<long long>(nums.begin(), nums.end()));
        queue<char, deque<char>> op_q2, op_q1(deque<char>(ops.begin(), ops.end())); 
        
        for (int i = 0; i < 3; ++i) 
        { 
            long long last = num_q1.front(); // last : 중간에 계산된 숫자를 저장 
            num_q1.pop(); 
            
            while (!op_q1.empty()) 
            { 
                if (op_q1.front() == op_order[i]) // 해당순위 연산자일 때 : 숫자 연산한 값을 last에 저장
                { 
                    last = calculate(last, num_q1.front(), op_q1.front());
                } 
                else // 해당순위 연산자가 아닐 때 : last를 q2에 저장 후, q1의 다음 숫자로 교체
                { 
                    op_q2.push(op_q1.front());
                    num_q2.push(last);
                    last = num_q1.front();
                } 
                op_q1.pop();
                num_q1.pop();
            }
            
            num_q2.push(last); // 마지막에 남은 숫자큐의 원소가 1개일 때 : 최대 절대값 갱신
            
            if (num_q2.size() == 1)
            { 
                answer = max(abs(num_q2.front()), answer); 
            }
            
            num_q1.swap(num_q2); // q1과 q2의 포인터 교환 
            op_q1.swap(op_q2);
        } 
    } while (next_permutation(op_order.begin(), op_order.end())); 
    
    return answer; 
}

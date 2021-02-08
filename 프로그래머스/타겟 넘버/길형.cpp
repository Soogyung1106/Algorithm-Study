#include <iostream>
#include <string>
#include <vector>

using namespace std;
int tar;
int count = 0;

void DFS(int index, int value, vector<int>& arr)
{
    if(index == arr.size())
    {
        if(tar == value) ++count;
    }
    else
    {
        DFS(index + 1, value + arr[index], arr);
        DFS(index + 1, value - arr[index], arr);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    tar = target;
    DFS(0, 0, numbers);
    answer = count;
    
    return answer;
}

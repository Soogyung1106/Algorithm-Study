#include <string>
#include <vector>
 
using namespace std;
 
vector<vector<int>> MAP;
 
void DFS(int x, int y, int Size, vector<int> &answer)
{
    bool Zero, One;
    Zero = One = true;
    for (int i = x; i < x + Size; i++)
    {
        for (int j = y; j < y + Size; j++)
        {
            if (MAP[i][j] == 0) One = false;
            if (MAP[i][j] == 1) Zero = false;
        }
    }
 
    if (Zero == true)
    {
        answer[0]++;
        return;
    }
    if (One == true)
    {
        answer[1]++;
        return;
    }
 
    DFS(x, y, Size / 2, answer);
    DFS(x, y + Size / 2, Size / 2, answer);
    DFS(x + Size / 2, y, Size / 2, answer);
    DFS(x + Size / 2, y + Size / 2, Size / 2, answer);
}
 
vector<int> solution(vector<vector<int>> arr) 
{
    vector<int> answer(2, 0);
    MAP = arr;
    DFS(0, 0, arr.size(), answer);
    return answer;
}

/* 
1. 문제를 해결하기 전에 문제를 접근해보자.
2. 사각형의 크기는 2^n x 2^n 이다.
3. 압축해야하는 사각형의 크기는 2^(n-1) * 2^(n-1) 이다.
4. 범위를 압축하려면 인덱스의 크기를 1/4, 2/4, 3/4, 4/4 분위로 나눠줘야함.
5. for문으로?.. while문으로?.. 전체 범위에서 size()만큼..? 2^n 이라 2^(n-1)이 되려면 /2를 해준다?..
6.0~ 2^n / 2 를 해주면 2^(n-1)이 된다. 그러면 0 ~ 2^(n-1) -1 // 2^n으로 범위를 나누어서 하면 되겠다?

7. for문으로 해주면 몇 중 for문을 사용해야하는가? 총 4번씩? 1/4, 2/4, 3/4, 4/4 범위만큼?
8. 그러면... 더 작아지면 8중 for문을? 어떻게 for문의 갯수를 늘릴 것인가?... -> 모르겠음..
9. 해결 못함... 다른 사람이 작성한 코드를 참고해보고 다시 생각해보자.


Solve. 분할-정복을 사용해서 문제를 해결한다. -> 개념을 알고 있었지만 사용해본적이 없어서 몰랐음.

New
1. 정복과 분할의 개념을 다시 찾아보고. 해당 문제에 대한 모델을 보고 코드를 분석해보고 다시 작성해본다.
2. 이번에는 문제 분석과 해답을 보고 내일 다시 풀어본다.

Note

1. DFS를 사용하여 재귀적으로 한다...!
2. 내가 생각한 개념과 맞다. 2^n / 2 를 하게되면 2^(n-1)이 되므로 이것을 이용하여 범위를 정해준다.
3. 특이한점은 MAP을 따로 작성해줘서 해당 범위의 Zero, One을 만들어줘서 bool의 형태로 압축을 측정한다. 만약 true 라면 1개로 압축되었으므로 answer에 1개만큼 올리지만, 아닌경우 재귀를 돌려 마지막까지 해결이 안되면 해당 범위 만큼 0과 1의 갯수를 가지게 된다.

*/

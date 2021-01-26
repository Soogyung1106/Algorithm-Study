#include <iostream>
#include <cmath>

using namespace std;

int solution(int n)
{
    int ans = 1;	//건전지 사용량 == 점프 거리
    int distance = n;	//남은거리

    while(distance > 1) 
    {	//남은거리가 1보다 크면 반복, 1되면 끝
        if( (distance % 2) == 0 ) 
        {	
            distance /= 2;
        }
        else 
        {	
            distance--;
            ans++;
        }
    }

    return ans;
}

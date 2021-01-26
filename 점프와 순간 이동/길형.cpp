#include <iostream>
#include <cmath>

using namespace std;

int solution(int n)
{
    int ans = 1;	

    while(n > 1) 
    {	
        if( (n % 2) == 0 ) 
        {	
            n /= 2;
        }
        else 
        {	
            n--;
            ans++;
        }
    }

    return ans;
}

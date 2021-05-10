#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool BinarySearch(vector<int> stones, int mid, int k)
{
	int count = 0;

	for (int i = 0; i < stones.size(); i++)
	{
		if (stones[i] - mid <= 0)
		{
			count++;
		}
		else
		{
			count = 0;
		}

		if (count >= k)
		{
			return true;
		}	
	}

	return false;
}

int solution(vector<int> stones, int k) 
{
	int answer = 0;

	int front = 1;
	int back = *max_element(stones.begin(), stones.end());

	while (front <= back)
	{
		int mid = (front + back) / 2;

		if (BinarySearch(stones, mid, k))
		{
			back = mid - 1;
		}
		else
		{
			front = mid + 1;
		}
	}
	return front;
}

//////////////////////////////////////////////
//
//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//int solution(vector<int> stones, int k) 
//{
//	int answer = 0;
//	int cnt = 0;
//
//	while (1) 
//	{
//		//돌다리 건널 수 있는지 판단하기
//		for (int i = 0; i < stones.size(); i++) 
//		{
//			if (cnt == k) break;

//			if (stones[i] <= 0) 
//			{
//				cnt++;
//			}
//			else cnt = 0;
//		}

//		if (cnt == k)break;
//		//돌다리 건너기
//		answer++;
//
//		//돌다리 줄이기
//		for (int i = 0; i < stones.size(); i++)
//		{
//			stones[i]--;
//		}
//
//		cnt = 0;
//	}
//
//	return answer;
//}

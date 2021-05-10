#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
int solution(vector<int> stones, int k) {
    int answer = 200000001;
    
    if(stones.size() == 1){
        answer = stones[0];
        return answer;
    }
    
    for(int i=0; i<=stones.size()-k; i++){
        answer = min(answer, *max_element((stones.begin() + i), (stones.begin() + i + k)));
    }
    
    return answer;
}
*/

bool check(int mid, vector<int>& stones, int k) {
	int cnt = 0;
	for (int i = 0; i < stones.size(); i++) {
		if (stones[i] - mid <= 0)
			cnt++;
		else
			cnt = 0;

		if (cnt >= k)
			return false;
	}
	return true;
}

int solution(vector<int> stones, int k) {
	int left = 1;
	int right = *max_element(stones.begin(), stones.end());
	int mid;
	while (left <= right) { 
        mid = (left + right) / 2;
		
        if (check(mid, stones, k)) {
            left = mid + 1;
        }
		else{
            right = mid - 1;
        }
	}
	return left;
}

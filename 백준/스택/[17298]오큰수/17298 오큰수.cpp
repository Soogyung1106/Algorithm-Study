#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int main() {

	//입력
	int N;
	cin >> N;

	vector <int> v(N);
	for (int i = 0; i < N; i++) 
		cin >> v[i];
	
	//오큰수
	stack <int> s;
	vector <int> ans(N, -1); //-1로 초기화
	for (int i = 0; i < v.size(); i++) { //v[i]: 비교하는 수 
		while (!s.empty() && v[s.top()] < v[i]) { //top에는 비교를 기다리는 인덱스
			ans[s.top()] = v[i]; 
			s.pop();
		}
		s.push(i); //인덱스를 push
	}

	//출력
	for (int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";

	return 0;
}
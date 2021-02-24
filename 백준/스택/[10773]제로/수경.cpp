#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main() {
	int n;
	cin >> n;
	
	stack<int> st;
	while (n--) {
		int num;
		cin >> num;

		if (num == 0) st.pop();
		else st.push(num);
	}

	if (st.empty()) cout << 0;
	else {
		int sum = 0;
		while (!st.empty()) {
			sum += st.top();
			st.pop();
		}
		cout << sum;
	}

	return 0;
}

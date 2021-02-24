#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;


int main() {
	int n;
	cin >> n;
	
	while (n--) {
		
		string s;
		cin >> s;

		stack<int> st; bool flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') st.push(s[i]);
			else {
				if (st.empty()) {
					flag = false;
					cout << "NO" << endl;
					break;
					//st.push(s[i]);
				}else st.pop();
			}	
		}

		if (!flag) continue;
		if (st.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;

	}

	return 0;
}

#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main() {

	while (1) {
		string str;
		getline(cin, str);

		if (str == ".") //종료조건
			break;

		stack<char> st;
		for (int i = 0; i < str.size() - 1; i++) {
			if (str[i] == '[' || str[i] == '(')
				st.push(str[i]);
			else {

				if (!isalpha(str[i]) && str[i] != ' ') { // ]나 )일 경우

					if (st.empty()) {
						st.push('x');
						break;
					}

					if (str[i] == ']') {
						if (st.top() == '[') st.pop();
						else st.push(str[i]);
					}

					if (str[i] == ')') {
						if (st.top() == '(') st.pop();
						else st.push(str[i]);
					}
				}
			}

		}

		if (st.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
	}



	return 0;
}

#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main() {
	int n;
	cin >> n;
	getchar(); //>>연산자 때문에 버퍼에 '\n' 

	stack<int> st;
	while (n--) {
		string s;
		getline(cin, s); //공백 있는 문자열 입력
		//cin >> s;

		if (s == "top") {
			if (st.empty()) cout << -1 << endl;
			else cout << st.top() << endl;
		}
		else if (s == "size")
			cout << st.size()<<endl;
		else if (s == "empty") {
			if (st.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (s == "pop") {
			if(st.empty()) cout << -1 << endl;
			else {
				cout << st.top() << endl;
				st.pop();
			}
		}
		else {
			string x = s.substr(5); //push 14 (5번째 자리부터)
			st.push(stoi(x));
		}
	}

	return 0;
}

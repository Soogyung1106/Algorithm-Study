#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string A, B;
int DP[1001][1001];
string LCS[1001][1001];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//freopen("input1.txt", "r", stdin);
	cin >> A >> B;

	for (int i = 1; i <= A.length(); i++) {
		for (int j = 1; j <= B.length(); j++) {

			if (A[i - 1] == B[j - 1]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
				LCS[i][j] = LCS[i][j] + LCS[i - 1][j - 1] + A[i - 1];
			
			}else{
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
				if (LCS[i - 1][j].length() > LCS[i][j - 1].length())  LCS[i][j] = LCS[i - 1][j];
				else  LCS[i][j] = LCS[i][j - 1];
			}

		}
	}

	cout << DP[A.length()][B.length()] << "\n" << LCS[A.length()][B.length()] << "\n";

	return 0;
}

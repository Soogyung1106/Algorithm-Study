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

	for (int i = 0; i < A.length(); i++) {
		for (int j = 0; j < B.length(); j++) {

			if (A[i] == B[j]) {
				DP[i+1][j+1] = DP[i][j] + 1;
				LCS[i+1][j+1] = LCS[i+1][j+1] + LCS[i][j] + A[i];
			
			}else{
				DP[i+1][j+1] = max(DP[i][j+1], DP[i+1][j]);
				if (LCS[i][j+1].length() > LCS[i+1][j].length())  LCS[i+1][j+1] = LCS[i][j+1];

				else  LCS[i+1][j+1] = LCS[i+1][j];
			}

		}
	}

	cout << DP[A.length()][B.length()] << "\n" << LCS[A.length()][B.length()] << "\n";

	return 0;
}

#include <iostream>
#include <memory.h>
#include <algorithm>
#include <string>
using namespace std;
bool isPrime[1004000];
int N;

void erathos() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[1] = false;

	for (int i = 2; i*i < 1004000; i++) {
		if (isPrime[i] == false) continue;
		for (int j = 2; i*j < 1004000; j++) isPrime[i*j] = false;
	}
}

bool isPalin(int n) {
	string str = to_string(n);
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - i - 1])
			return false;
	}
	return true;
}

int main()
{
	cin >> N;

	erathos();

	for (int i = N;; i++) {
		if (isPrime[i] == false) continue;
		if (isPalin(i)) {
			cout << i;
			break;
		}
	}
}

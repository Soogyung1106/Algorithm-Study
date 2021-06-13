#include <bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	cin>>s;
	cout<<(regex_match(s,regex("(100+1+|01)+"))?"SUBMARINE":"NOISE");
}

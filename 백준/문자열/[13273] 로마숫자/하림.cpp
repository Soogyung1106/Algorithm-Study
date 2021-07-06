//
//  main.cpp
//  [13273] 로마숫자
//
//  Created by 정하림 on 2021/07/06.
//

#include <iostream>
#include <string>

using namespace std;

string board_1000[4] = { "", "M", "MM", "MMM"};
string board_100[10] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
string board_10[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
string board_1[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

string arabia_to_roma(string s){
    string result = "";
    int num = stoi(s);
    
    result += board_1000[num/1000];
    num %= 1000;
    
    result += board_100[num/100];
    num %= 100;
    
    result += board_10[num/10];
    num %= 10;
    
    result += board_1[num];
    
    return result;
}

string roma_to_arabia(string s){
    int result = 0;
    
    for(int i=s.length()-1; i>=0; i--){
        if(s[i] == 'I'){
            result++;
        }
        else if(s[i] == 'V'){
            if( i-1 > -1 && s[i-1] == 'I' ){
                result += 4;
                i--;
            }
            else{
                result += 5;
            }
        }
        else if(s[i] == 'X'){
            if( i-1 > -1 && s[i-1] == 'I' ){
                result += 9;
                i--;
            }
            else{
                result += 10;
            }
        }
        else if(s[i] == 'L'){
            if( i-1 > -1 && s[i-1] == 'X' ){
                result += 40;
                i--;
            }
            else{
                result += 50;
            }
        }
        else if(s[i] == 'C'){
            if( i-1 > -1 && s[i-1] == 'X' ){
                result += 90;
                i--;
            }
            else{
                result += 100;
            }
        }
        else if(s[i] == 'D'){
            if( i-1 > -1 && s[i-1] == 'C' ){
                result += 400;
                i--;
            }
            else{
                result += 500;
            }
        }
        else if(s[i] == 'M'){
            if( i-1 > -1 && s[i-1] == 'C' ){
                result += 900;
                i--;
            }
            else{
                result += 1000;
            }
        }
    }
    
    return to_string(result);
}

string solution(){
    string s;
    cin >> s;
    
    if( s[0] >= '0' && s[0] <= '9' ){
        return arabia_to_roma(s);
    } else {
        return roma_to_arabia(s);
    }
}

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for(int t=0; t<T; t++){
        cout << solution() << "\n";
    }
    
    return 0;
}

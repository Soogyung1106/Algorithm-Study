#include <iostream>
#include <vector>

using namespace std;

int N,S;
vector<int> progression;

void input() {
    cin >> N >> S;
     
    int temp;
     
    for(int i=0; i<N; i++){
        cin >> temp;
        progression.push_back(temp);
    }
}

void solution() {
    int answer = N+1;
    int head = 0, tail = 0;
    int sum = 0;
    
    while(true){
        if(sum >= S){
            answer = min(answer, tail - head);
            sum = sum - progression[head];
            head++;
        }
        else if(tail == N){
            break;
        }
        else{
            sum = sum + progression[tail];
            tail++;
        }
    }
     
    if(answer == N+1){
        answer = 0;
    }
    
    cout << answer;
}

int main(int argc, const char * argv[]) {
    
    input();
        
    solution();
    
    return 0;
}


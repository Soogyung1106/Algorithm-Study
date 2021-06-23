//
//  main.cpp
//  [19942] 다이어트
//
//  Created by 정하림 on 2021/06/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, mp, mf, ms, mv;

int min_cost = 15 * 500 + 1;

struct food{
    int p, f, s, v, c;
};

food foods[15];

vector<int> index_v, result;

void input(){
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    
    for(int i=0; i<N; i++){
        cin >> foods[i].p >> foods[i].f >> foods[i].s >> foods[i].v >> foods[i].c;
    }
}

void dfs(int index, int sum_p, int sum_f, int sum_s, int sum_v, int cost){
    if( sum_p>=mp && sum_f>=mf && sum_s>=ms && sum_v>=mv){
        if(cost < min_cost){
            min_cost = cost;
            result = index_v;
        }
        return;
    }
    if(index==N){
        return;
    }
    
    index_v.push_back(index);
    dfs(index+1, sum_p+foods[index].p, sum_f+foods[index].f, sum_s+foods[index].s, sum_v+foods[index].v, cost+foods[index].c);
    index_v.pop_back();
    
    dfs(index+1, sum_p, sum_f, sum_s, sum_v, cost);

}

void output(){
    if(min_cost == 15 * 500 + 1){
        cout << "-1";
        return;
    }
    
    cout << min_cost << "\n";
    
    sort(result.begin(), result.end());
    
    for(auto r : result){
        cout << r+1 << " ";
    }
}

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    
    dfs(0,0,0,0,0,0);
    
    output();
    
    return 0;
}



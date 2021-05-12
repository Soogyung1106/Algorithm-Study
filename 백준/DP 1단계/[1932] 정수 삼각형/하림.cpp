//
//  main.cpp
//  정수 삼각형
//
//  Created by 정하림 on 2021/05/12.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    vector<vector<int>> sum_triangle(triangle);
    
    for(int i = 0; i < sum_triangle.size()-1; i++){
        for(int j = 0; j < sum_triangle[i].size(); j++ ){
            int left = sum_triangle[i][j] + triangle[i+1][j];
            int right = sum_triangle[i][j] + triangle[i+1][j+1];
            
            sum_triangle[i+1][j] = max(sum_triangle[i+1][j],left);
            sum_triangle[i+1][j+1] = max(sum_triangle[i+1][j+1], right);
        }
    }
    
    answer = *max_element( sum_triangle[sum_triangle.size()-1].begin(), sum_triangle[sum_triangle.size()-1].end() );
    
    return answer;
}

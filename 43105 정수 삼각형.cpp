#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> answer = triangle;
    
    for (int i = 1; i < triangle.size(); i++){
        
        answer[i][0] = answer[i-1][0] + triangle[i][0];
        
        for (int j = 1; j < triangle[i].size()-1; j++){
            answer[i][j] = max(answer[i-1][j], answer[i-1][j-1]) + triangle[i][j];
        }
        
        int j = triangle[i].size()-1;
        answer[i][j] = answer[i-1][j-1] + triangle[i][j];
    }
    
    return *max_element(answer.back().begin(), answer.back().end());
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int rows = board.size();
    int cols = board[0].size();
    
    vector<vector<int>> change(rows+1, vector<int>(cols+1,0));
    
    for (auto sk : skill){
        int num;
        if (sk[0] == 1) num = -sk[5];
        else num = sk[5];
        
        change[sk[1]][sk[2]] += num;
        change[sk[1]][sk[4]+1] -= num;
        change[sk[3]+1][sk[2]] -= num;
        change[sk[3]+1][sk[4]+1] += num;      
    }
    
    for (int i = 0; i<rows; i++){
        for (int j=0; j<cols; j++)
            if (i != 0) change[i][j] += change[i-1][j];
    }
    
    for (int i = 0; i<rows; i++){
        for (int j=0; j<cols; j++){
            if (j != 0) change[i][j] += change[i][j-1];
            if (board[i][j] + change[i][j] > 0)
                answer++; 
        }
    }

    return answer;
}
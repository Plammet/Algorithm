#include <string>
#include <vector>

using namespace std;

bool check(vector<string>room, int row, int col, int count){
    room[row][col] = 'X';
    
    int row_move[4] = {-1, 1, 0, 0};
    int col_move[4] = {0, 0, -1, 1};
    
    for (int i = 0; i < 4; i++){
        int next_row = row+row_move[i];
        int next_col = col+col_move[i];
        
        if (next_row>=0 && next_row<5 && next_col>=0 && next_col<5){
            if (room[next_row][next_col] == 'P') return 0;
            
            if (count<1){
                if (room[next_row][next_col] == 'O')
                    if (check(room, next_row, next_col, count+1) == 0) return 0;
                
            }
        }
    }
    
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (auto room : places){
        int ok = 1;
        for (int i=0; i<5; i++){
            if (ok==0) break;
            for (int j=0; j<5; j++){
                if (ok==0) break;
                if (room[i][j] == 'P')
                    ok = check(room, i, j, 0);
            }
        }
        
        answer.push_back(ok);
    }
    
    return answer;
}
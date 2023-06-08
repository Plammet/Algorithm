#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(int num, vector<vector<int>> &vec){
    if (vec[num][num] == 0) return;
    else vec[num][num] = 0;
    
    for (int i = 0; i < vec.size(); i++){
        if (vec[num][i] == 1){
            dfs(i, vec);  
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; i++){
        if (computers[i][i] == 1){
            dfs(i, computers);
            answer++;
        }
    }
    
    return answer;
}
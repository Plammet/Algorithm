#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<vector<int>> dungeons, vector<int> visited, int pirodo){
    int result = 0;
    
    for (int i=0; i<visited.size(); i++){
        vector<int> next = dungeons[i];
        if (visited[i] == 0 && pirodo >= next[0]){
            vector<int> new_visited = visited;
            new_visited[i] = 1;
            result = max(result, dfs(dungeons, new_visited, pirodo-next[1])+1);
        }
    }
    
    return result;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> visited(dungeons.size(),0);
    
    answer = dfs(dungeons, visited, k);
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> new_array;
    
    for (vector<int>cmd : commands){
        for(int i = cmd[0]; i <= cmd[1]; i++){
            new_array.push_back(array[i-1]);
        }
        sort(new_array.begin(), new_array.end());
        new_array.clear();
        answer.push_back(new_array[cmd[2]-1]);
    }
    return answer;
}
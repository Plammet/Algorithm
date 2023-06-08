#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> finished;
    
    for (string name : participant)
        finished[name]++;
    for (string name : completion)
        finished[name]--;
    for (auto pair : finished)
        if (pair.second == 1)
            answer = pair.first;
    
    return answer;
}
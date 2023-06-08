#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> clothes_number;
    
    for (auto pair : clothes)
        clothes_number[pair[1]]++;
    
    for (auto pair : clothes_number){    
        int n = pair.second;
        answer *= (n+1);
    }
    
    answer --;
    return answer;
}
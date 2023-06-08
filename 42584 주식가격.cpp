#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> stack = {0};
    vector<int> answer = prices;
    
    int temp;
    
    for (int i = 1; i < prices.size(); i++){
        
        while(!stack.empty() && prices[i] < prices[stack.back()]){
            answer[stack.back()] = i-stack.back();
            stack.pop_back();
        }
        stack.push_back(i);
    }
    
    for (auto i : stack){
        answer[i] = prices.size()-i-1;
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    vector<int> stack;
    int conv = 1;
    
    for (int ord : order){
        if (ord == conv){
            answer++;
            conv++;
        }
        
        else if (!stack.empty() && ord == stack.back()){
            answer++;
            stack.pop_back();
        }
        
        else if (ord > conv){
            while(ord > conv){
                stack.push_back(conv);
                conv++;
            }
            answer++;
            conv++;
        }
        
        else break;
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int L_plus_H = (brown-4)/2;
    
    for(int i = 1; i<L_plus_H; i++){
        int a = yellow%i;
        int h = yellow/i;
        
        if (a == 0 && h+i == L_plus_H){
            answer.push_back(h+2);
            answer.push_back(i+2);
            return answer;
        }
    }
    
    return answer;
}
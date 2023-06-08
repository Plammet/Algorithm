#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> leftDays;
    for (int i = 0; i<progresses.size(); i++){
        leftDays.push_back(ceil((float)(100 - progresses[i])/speeds[i]));
    }
    
    int days = leftDays[0];
    int j = 0;
    
    for (int i=0; i<leftDays.size(); i++){
        if (leftDays[i] <= days){
            j++;
        }
        else {
            answer.push_back(j);
            days = leftDays[i];
            j = 1;
        }
    }
    answer.push_back(j);
    return answer;
}
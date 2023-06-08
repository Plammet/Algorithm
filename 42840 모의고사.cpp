#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> correct = {0, 0, 0};
    
    vector<int> student1 = {1, 2, 3, 4, 5};
    vector<int> student2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> student3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < answers.size(); i++){
        if (answers[i] == student1[i%5]) correct[0]++;
        if (answers[i] == student2[i%8]) correct[1]++;
        if (answers[i] == student3[i%10]) correct[2]++;
    }
    
    int max = *max_element(correct.begin(), correct.end());
    
    for (int i = 0; i < 3; i++)
        if (correct[i] == max) answer.push_back(i+1);
    
    return answer;
}
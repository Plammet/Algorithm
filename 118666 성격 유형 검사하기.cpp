#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<string, int> score = {
        {"R", 0}, {"T", 0},
        {"C", 0}, {"F", 0},
        {"J", 0}, {"M", 0},
        {"A", 0}, {"N", 0}, 
    };
    
    for (int i = 0; i<survey.size(); i++){
        string temp = "";
        
        if (choices[i] < 4){
            temp.push_back(survey[i][0]);
            score[temp] += 4 - choices[i]; 
        }
        
        else if (choices[i] > 4){
            temp.push_back(survey[i][1]);
            score[temp] += choices[i] - 4;
        }
    }
    
    if (score["R"] >= score["T"]) answer.append("R");
    else answer.append("T");
    
    if (score["C"] >= score["F"]) answer.append("C");
    else answer.append("F");
    
    if (score["J"] >= score["M"]) answer.append("J");
    else answer.append("M");
    
    if (score["A"] >= score["N"]) answer.append("A");
    else answer.append("N");
    
    return answer;
}
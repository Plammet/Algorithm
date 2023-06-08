#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string, vector<int>> people;
    
    for (string p : info){
        auto iter = p.begin();
        
        string type = "";
        
        for (int i=0; i<4; i++){
            type.push_back(*(iter));
            iter = find(iter, p.end(), ' ')+1;
        }
        
        string s(iter, p.end());
        int coding = stoi(s);
        
        people[type].push_back(coding);
    }

    for (string q : query){
        int pass = 0;
        auto iter = q.begin();
        string type = "";
        
        for (int i=0; i<7; i++){
            if (*(iter) != 'a')
                type.push_back(*(iter));
            
            iter = find(iter, q.end(), ' ')+1;
        }
        
        string s(iter, q.end());
        int cutline = stoi(s);
        
        for (auto a : people){
            int ok = 1;
            for (int i=0; i<4 ;i++){
                if(type[i] != a.first[i] && type[i] != '-'){
                    ok = 0;
                    break;
                }
            }
            
            if (ok == 1){
                for (int score : a.second)
                    if (score >= cutline) pass++;
            }
            
        }
        
        
        answer.push_back(pass);
        
    }
    return answer;
}
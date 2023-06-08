#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    
    unordered_map<string, int> ID_number;
    unordered_map<string, unordered_set<string>> ID_reported;
    unordered_map<string, unordered_set<string>> reported_ID; 
    
    for (int i = 0; i < id_list.size(); i++){
        ID_number[id_list[i]] = i; 
    }
    
    for (string s : report){
        int seperator = s.find(" ");
        string id = s.substr(0, seperator);
        string reported = s.substr(seperator+1);
        
        ID_reported[id].insert(reported);
        reported_ID[reported].insert(id);
    }
    
    for (pair p : reported_ID){
        if (p.second.size() >= k){
            for (string user : p.second){
                answer[ID_number[user]]++;
            }
        }
    }
    return answer;
}
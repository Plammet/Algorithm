#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return (p1.second > p2.second);
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> count;  // 숫자, 횟수
    string temp = "";
    
    for (char c : s){
        if (isdigit(c)) temp.push_back(c);
        else if (temp != ""){
            int num = stoi(temp);
            
            if (count.find(num) == count.end()) count[num] = 1;
            else count[num]++;
            
            temp = ""; 
        }
    }
    
    vector<pair<int,int>> new_count(count.begin(), count.end());
    sort(new_count.begin(), new_count.end(), compare);
    
    for (auto num : new_count)
        answer.push_back(num.first);
    
    return answer;
}
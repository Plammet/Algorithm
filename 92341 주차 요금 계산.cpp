#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;


bool compare(string s1, string s2){
    
    if (s1.substr(6,4) != s2.substr(6,4))
        return (s1.substr(6,4) < s2.substr(6,4));
    
    else return (s1.substr(0,5) < s2.substr(0,5));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> cars;
    
    sort(records.begin(), records.end(), compare);
    
    int inTime = 0;
    int outTime = 0;
    int times = 0;
    string carNum;
    for (auto rec : records){
        if (carNum != ""){
            if (rec.substr(11,2) == "OU"){
                outTime += stoi(rec.substr(0,2)) * 60;
                outTime += stoi(rec.substr(3,2));
            }
            else outTime = 1439;
        
            times = outTime-inTime;
            if (cars.find(carNum) == cars.end()) cars[carNum] = times;
            else cars[carNum] += times;
            
            carNum = "";
            inTime = 0;
            outTime = 0;
        }
        
        if (rec.substr(11,2) == "IN"){
            carNum = rec.substr(6,4);
            inTime += stoi(rec.substr(0,2)) * 60;
            inTime += stoi(rec.substr(3,2));
            
        }
    }
    if (carNum != ""){
        times = 1439-inTime;
        if (cars.find(carNum) == cars.end()) cars[carNum] = times;
        else cars[carNum] += times;
    }

    for (auto c : cars){
        int fee = fees[1];
        int times = c.second;
        
        if (times > fees[0]){
            times -= fees[0];
            fee += (times/fees[2]) * fees[3];
            if(times%fees[2] != 0) fee += fees[3];
        }
        
         answer.push_back(fee);
    }
    
    return answer;
}

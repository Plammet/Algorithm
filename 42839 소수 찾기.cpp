#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <set>

using namespace std;

void all_numbers(set<int>& all, string now, string remain){
    for (int i=0; i<remain.size(); i++){
        string new_remain = remain;
        all.insert(stoi(now + remain[i])); 
        
        new_remain.erase(i,1);
        
        if (new_remain.size() == 0) return;
        else all_numbers(all, now+remain[i], new_remain);
    }
}

vector<int> primary(int n){
    vector<int> answer(n+1,1);
    
    answer[0] = 0;
    answer[1] = 0;
    
    for(int i = 2; i<=sqrt(n); i++){
        for (int j=2; i*j < n+1; j++){
            answer[i*j] = 0;   
        }
    }
    
    return answer;
}

int solution(string numbers) {
    int answer = 0;
    set<int> all;
    
    all_numbers(all, "", numbers);
    
    
    vector<int> p = primary(*all.rbegin());
    
    for (int n : all){
        if (p[n] == 1) {
            cout << n << " ";
            answer++;
        }
    }

    return answer;
}


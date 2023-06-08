#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    for (int i = 1; i < words.size(); i++){
        if (words[i-1].back() != words[i].front())
            return {i%n+1, i/n+1};
        
        for(int j = 0; j < i; j++){
            if (words[i] == words[j])
                return {i%n+1, i/n+1};
        }
    }
                         
    return {0,0};
}
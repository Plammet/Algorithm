#include <string>
#include <vector>

using namespace std;


vector<int> binary(unsigned int number){
    int zeros = 0;
    int ones = 0;
    
    if(number == 2) return {1, 1};
    
    while(number > 0){
        if (number%2 == 0) zeros++;
        else ones++;
        number>>=1;
    }  
    return {ones, zeros};
}

vector<int> solution(string s) {    
    vector<int> answer;
    int count = 1;
    int zeros = 0;
    int ones = 0;
    
    for (auto c : s){
        if (c == '0') zeros++;
        else if (c == '1') ones++;
    }
    
    while(ones != 1){
        answer = binary(ones);
        ones = answer[0];
        zeros += answer[1];
        count++;
    }
    
    return {count, zeros};
}
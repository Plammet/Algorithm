#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;

void add(vector<int> numbers, int index, int target, int sum){
    if (index == numbers.size()-1){
        
        if (sum + numbers[index] == target) answer++;
        if (sum - numbers[index] == target) answer++;
        
        return;
    }
    
    else{
        add(numbers, index+1, target, sum + numbers[index]);
        add(numbers, index+1, target, sum - numbers[index]); 
    }
    
}


int solution(vector<int> numbers, int target) {
    
    add(numbers, 0, target, 0);
    
    return answer;
}
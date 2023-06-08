#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {    
    if (numbers.size() == 10) return -1;
    
    int answer = 0;
    for (int i = 0; i < 10; i++){
        if (find(numbers.begin(), numbers.end(), i) == numbers.end())
            answer += i;
    }
    

    return answer;
}
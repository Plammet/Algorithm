#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer;
    istringstream ss(s);
    vector<int> numbers;
    int token;
    
    while(ss >> token)
        numbers.push_back(token);
    
    sort(numbers.begin(), numbers.end());

    answer = to_string(numbers.front()) + " ";
    answer.append(to_string(numbers.back()));
    
    return answer;
}
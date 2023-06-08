#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int a = s/n;
    int b = s - (a * n);
    
    if (a == 0) return {-1};
        
    for (int i = 0; i < n-b; i++) answer.push_back(a);
    
    for (int i = 0; i < b; i++) answer.push_back(a+1);
    
    return answer;
}
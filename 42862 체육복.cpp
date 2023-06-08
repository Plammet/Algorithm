#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> student(n+1,1);
    vector<int> real_reserve;
    
    for (int num : lost){
        student[num] = 0;
    }
    
    for (int num : reserve){
        if (student[num] == 0) student[num] = 1;
        else real_reserve.push_back(num);
    }
    
    sort(real_reserve.begin(), real_reserve.end());
    
    for (int num : real_reserve){
        if (student[num] == 0)
            student[num] = 1;
        
        else if (student[num-1] == 0)
            student[num-1] = 1;
        
        else if (num<n && student[num+1] == 0)
            student[num+1] = 1;
    }
    
    for (int st : student){
        if (st == 1) answer++;
    }
    
    return answer-1;
}
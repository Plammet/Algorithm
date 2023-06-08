#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {    
    long long answer = 0;
    long long time = 0;
    
    sort(times.begin(), times.end());
    
    long long min = 1;
    long long max = (long long)times.back() * n;
    
    while(min<=max){
        long long people = 0;
        time = (min+max)/2;
        
        for (auto a : times){
            people += time/a;
        }
        
        if (people < n)
            min = time+1;
        
        else{
            max = time-1;
            answer = time;
        }
    } 
    return answer;
}
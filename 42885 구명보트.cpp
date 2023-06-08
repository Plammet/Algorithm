#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int left = 0;
    int iter = 0;
        
    sort(people.begin(), people.end());
    
    while(people.size() > iter ){
        left = limit - people.back();
        answer++;
        
        people.pop_back();

        if (people.size() > iter && people.at(iter) <= left )
            iter++;
    }
    
    return answer;
}
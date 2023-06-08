#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int>& vec1, vector<int>& vec2){
    return vec1[1] < vec2[1];
}


int solution(vector<vector<int>> routes) {
    int answer = 1;
    int loc = 0;
    
    sort(routes.begin(), routes.end(), comp);
    
    loc = routes[0][1];
    
    for (auto route : routes){
        if (route[0] > loc){
            answer++;
            loc = route[1];
        }
    }
    
    return answer;
}
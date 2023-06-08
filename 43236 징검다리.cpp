#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    
    int min = 0;
    int max = distance;
    
    while(min<=max){
        int mid = (min+max)/2;
        int count = 0;
        int prev = 0;
        
        cout<<mid<<" ";
        
        for (int rock : rocks){
            if (rock - prev < mid) count++;
            else prev = rock;
        }
        
        if (distance - rocks.back() < mid) count++;
        
        if (count > n) max = mid-1;
        else{
            min = mid+1;
            answer = mid;
        }
    }
    
    return answer;
}
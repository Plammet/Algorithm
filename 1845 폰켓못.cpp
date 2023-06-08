#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> mons;
    
    for (int i : nums)
        mons.insert(i);
    
    if (mons.size() >= nums.size()/2) answer = nums.size()/2;
    else answer = mons.size();
    
    return answer;
}
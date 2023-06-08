#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int found = 0;
    int zero = 0;
    
    for (int num : lottos){
        if (num == 0)
            zero++;
        else if (find(win_nums.begin(), win_nums.end(), num) != win_nums.end())
            found++;
    }
    
    if (found == 0) found = 1;
    if (zero == 6) zero = 5;
    
    answer.push_back(7-found-zero);
    answer.push_back(7-found);
    
    return answer;
}
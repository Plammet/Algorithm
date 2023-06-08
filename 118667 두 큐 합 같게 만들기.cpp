#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int limit = queue1.size() *3 ;
    long long int sum1 = 0;
    long long int sum2 = 0;
    int margin;
    int iter1 = 0;
    int iter2 = 0;
    
    for (auto num : queue1){
        sum1 += num;
    }
    
    for (auto num : queue2){
        sum2 += num;
    }
    
    if ((sum1%2) + (sum2%2) == 1) return -1;
    
    margin = sum1 - sum2;
    
    while(margin != 0){
        
        if (answer > limit) return -1;
        
        if (margin > 0){
            margin -= queue1[iter1] * 2;
            queue2.push_back(queue1[iter1]);
            iter1++;
            answer++;
        }
        else if (margin < 0){
            margin += queue2[iter2] * 2;
            queue1.push_back(queue2[iter2]);
            iter2++;
            answer++;
        }
    
    }
    return answer;
}
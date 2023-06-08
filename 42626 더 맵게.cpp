#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> queue;
    
    for (int number : scoville){
        queue.push(number);
    }
    
    while (queue.top() < K){
        if (queue.size() > 1){
            int n1 = queue.top();
            queue.pop();
            int n2 = queue.top();
            queue.pop();
            int new_food = n1 + n2*2;
        
            queue.push(new_food);
            answer ++;
        }
        else return -1;
       
    }
    return answer;
}
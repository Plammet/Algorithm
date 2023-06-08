#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if (n==1 || n == 2) return 1;
    
    int answer = 0;
    
    int start = n/2 + 1;
    int add = 0;
    
    for (int i = start; i > 0; i--){
        add += i;
        if (add == n){
            answer++;
            add -= start;
            start--;
        }
        else if (add > n){
            add -= start;
            start--;
        }
    }
    return answer+1;
}
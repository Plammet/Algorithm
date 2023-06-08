#include <string>
#include <vector>

using namespace std;

int ones (int n) {
    int ones = 0;
    
    while ( n > 0 ){
        if ( n%2 == 1) ones++;
        n /= 2;
    }
    
    return ones;
}

int solution(int n) {
    int answer = n + 1;
    int n_ones = ones(n);
    
    while(true){
        if (ones(answer) == n_ones) return answer; 
        answer++;
    }
}


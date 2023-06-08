#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int a = 0, b = 1;

    for (int i=0; i < n-1; i++){
        answer = (a + b)%1234567;
        a = b;
        b = answer;
    }
    
    return answer%1234567;
}
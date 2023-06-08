#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int num1, int num2);
int LCM (int num1, int num2);

int solution(vector<int> arr) {
    
    sort(arr.begin(), arr.end());
    int answer = arr[0];
    
    for (int i = 1; i < arr.size(); i++){
       answer = LCM(answer, arr.at(i));
    }
    return answer;
}

int GCD(int num1, int num2){
    if (num1 > num2){
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    if (num2%num1 == 0) return num1;
    else return GCD(num2%num1, num1);
}

int LCM (int num1, int num2){
    return num1 * num2 / GCD(num1, num2);
}
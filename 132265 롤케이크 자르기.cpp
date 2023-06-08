#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int cut = topping.size()/2;
    
    vector<int> chul(10001, 0);
    vector<int> bro(10001, 0);
    
    int chul_size = 0;
    int bro_size = 0;
    
    for (int t : topping){
        if (bro[t] == 0) bro_size++;
        bro[t]++;
    }

    for (int j = 0; j<topping.size(); j++){
        int top = topping[j];
        
        if (chul[top] == 0) chul_size++; 
        chul[top]++;
        
        if (bro[top] == 1) bro_size--;
        bro[top]--;
        
        if (chul_size == bro_size) answer++;
    }
    
    return answer;
}
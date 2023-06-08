#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

int nn(int n, int count){
    int result = n;
    for (int i = 1; i<count; i++){
        result *= 10;
        result += n;
    }
    return result;
}

int solution(int N, int number) {
    int answer = 0;
    
    vector<unordered_set<int>> results(8); 
    unordered_set<int> test;
    
    for (int i=0; i<8; i++){
        
        int nnn = nn(N, i+1);
        if (nnn == number) return i+1;
        else results[i].insert(nnn);
        
        for (int j=0; j<i; j++){
            for (int numA : results[j]){
                for (int numB : results[i-j-1]){
                    
                    int a = max(numA, numB);
                    int b = min(numA, numB);
                    
                    if (a+b == number) return i+1;
                    else results[i].insert(a+b);
                    
                    if (a-b == number) return i+1;
                    else results[i].insert(a-b);
                    
                    if (a*b == number) return i+1;
                    else results[i].insert(a*b);
                    
                    if (b != 0){
                        if (a/b == number) return i+1;
                        else results[i].insert(a/b);
                    }
                }
            }
        }
    }
    return -1;
}
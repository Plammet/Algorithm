#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<long long> to_n(int number, int k){
    vector<long long> result;
    long long temp = 0;
    long long jari = 1;
    
    while(number!=0){
        if (number%k == 0){
            if (temp!=0) result.push_back(temp);
            number = number/k;
            temp = 0;
            jari = 1;
        }
        else{
            temp += jari * (long long)(number%k);
            number = number/k;
            jari *= 10;
        }
    }
    result.push_back(temp);
    return result;
}

int is_prime(long long n){
    if (n==1) return 0;
    if (n==2) return 1;
    
    for (long long i = 2; i<=sqrt(n); i++){
        if (n%i == 0)return 0;
    }
    
    return 1;
}

int solution(int n, int k) {
    int answer = 0;
    
    vector<long long> changed = to_n(n,k);
    
    for (long long num : changed){
        if (is_prime(num)) answer++;
    }
    
    return answer;
}

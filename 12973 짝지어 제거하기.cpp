#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    string str;
    
    for (auto c : s){
        if (str.back() == c)
            str.pop_back();
        
        else str.push_back(c);
    }

    return str.empty();
}
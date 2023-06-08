#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int top = 0;
    
    for (int i=0; i < s.length(); i++){
        if ( top < 0) return false;
        
        if (s[i] == '(') top++;
        else if (s[i] == ')') top--;
    }
    
    return top==0;
}
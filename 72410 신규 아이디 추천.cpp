#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    string changed = "";
    int dots = 1;
    
    for (char c : new_id){
        if (isupper(c)){
            changed.push_back(tolower(c));
            dots=0;
        }
        
        if (isdigit(c) || islower(c) || c=='-' || c== '_'){
            changed.push_back(c);
            dots=0;
        }
        
        if (c == '.' && dots == 0){
            changed.push_back(c);
            dots=1;
        }
    } 
    
    if (changed == "") changed = "a";
    
    if (changed.size() > 15) changed = changed.substr(0,15);
    if (changed.back() == '.') changed.pop_back();
    
    for (int i = changed.size(); i<3; i++){
        changed.push_back(changed.back());
    }
    
    return changed;
}
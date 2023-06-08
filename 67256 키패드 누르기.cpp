#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l = 10; // 각 손의 위치 *=10, 0=11, #=12
    int r = 12;
    
    for (int num : numbers){
        if (num==1 || num==4 || num==7){
            answer.push_back('L');
            l = num; 
        }
        else if (num==3 || num==6 || num==9){
            answer.push_back('R');
            r = num; 
        }
        else{
            if (num==0) num=11;
            
            int l_dist;
            int r_dist;
            
            if (l%3==2) l_dist = abs(l-num)/3;
            else l_dist = abs(l+1-num)/3 + 1;
            
            if (r%3==2) r_dist = abs(r-num)/3;
            else r_dist = abs(r-1-num)/3 + 1;
            
            if (l_dist < r_dist){
                answer.push_back('L');
                l = num;
            }
            else if (l_dist > r_dist){
                answer.push_back('R');
                r = num;
            }
            
            else if (l_dist == r_dist){
                if (hand=="left"){
                    answer.push_back('L');
                    l = num;
                }
                else{
                    answer.push_back('R');
                    r = num;
                }
            }
        }
    }
    
    return answer;
}
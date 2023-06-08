#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> lion(11,0);
    int max_score = 0;
    
    for (int i = 0; i<2048; i++){
        int apeach_score = 0;
        int score = 0;
        int count = 0;
        int cases = i;
        
        for  (int j = 0; j<11; j++){
            if (cases%2 == 1){
                score += 10-j;
                count += info[j]+1;
                lion[j] = (info[j]+1);
                if (count > n) break;
            }
            else lion[j] = 0;
            
            cases /= 2;
        }
        
        for (int i = 0; i<11; i++){
            if (info[i]!=0 && lion[i]==0)
                apeach_score += (10-i);
        }
        
        if (count <= n && score-apeach_score >= max_score){
            if (count < n) lion[10] += n-count;
            max_score = score-apeach_score;
            answer = lion;
        }
    }
    
    if (max_score == 0) return {-1};
    else return answer;
}
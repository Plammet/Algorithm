#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int maxalp = 0;
    int maxcop = 0;
    vector<vector<int>> table(151, vector<int>(151, 1000));
    
    table[alp][cop] = 0;
    
    for (auto p : problems){
        if (p[0] > maxalp) maxalp = p[0];
        if (p[1] > maxcop) maxcop = p[1];
    }
    
    if (maxalp < alp) maxalp = alp;
    if (maxcop < cop) maxcop = cop;
        
    for (int i=alp; i<=maxalp; i++){
        for (int j=cop; j<=maxcop; j++){
            int time = table[i][j];
            int after_alp = min(maxalp, i+1);
            int after_cop = min(maxcop, j+1);
            
            table[after_alp][j] = min(time+1, table[after_alp][j]);
            table[i][after_cop] = min(time+1, table[i][after_cop]);
            
            for (auto p : problems){
                if (i >= p[0] && j >= p[1]){
                    after_alp = min(maxalp, i+p[2]);
                    after_cop = min(maxcop, j+p[3]);
                    table[after_alp][after_cop] =
                        min(time + p[4],  table[after_alp][after_cop]);
                }
            }
        }
    }
    
    return table[maxalp][maxcop];
}
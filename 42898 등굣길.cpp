#include <string>
#include <cstring>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int map[n][m];
    
    memset(map, 0, sizeof(map));
    
    for (auto p : puddles){
        map[p[1]-1][p[0]-1] = -1;
    }
    
    for (int i=0; i<m; i++){
        if (map[0][i] == -1) break;
        else map[0][i] = 1;
    }   
    for (int i=0; i<n; i++){
        if (map[i][0] == -1) break;
        else map[i][0] = 1;
    } 
    
    for (int i=1; i<n; i++){
        for (int j=1; j<m; j++){
            if (map[i][j] == -1) continue;
            
            if (map[i-1][j] != -1) 
                map[i][j] += map[i-1][j];
            
            if (map[i][j-1] != -1) 
                map[i][j] += map[i][j-1];
            
            map[i][j] = map[i][j]%1000000007;
        }
    }
    
    return map[n-1][m-1];
}
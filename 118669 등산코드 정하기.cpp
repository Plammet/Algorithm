#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {

    vector<vector<pair<int, int>>> connect(n+1);
    vector<int> check(n+1, 0);  //0-쉼터 1-출입구or산봉우리
    vector<int> intensity(n+1, 20000000);
    queue<int> q;
    
    for (auto path : paths){
        int a = path[0];
        int b = path[1];
        
        connect[a].push_back(make_pair(b, path[2]));
        connect[b].push_back(make_pair(a, path[2]));
    }
    
    for (auto gate : gates){
        check[gate] = 1;
        intensity[gate] = 0;
        q.push(gate);
    }
    
    for (auto summit : summits){
        check[summit] = 1;
    }
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for (int i=0; i<connect[now].size(); i++){
            pair<int, int> loc = connect[now][i];
            
            int new_intensity = max(intensity[now],loc.second);
            
            if (new_intensity < intensity[loc.first]){
                intensity[loc.first] = new_intensity;
                
                //gate와 summit이 아닐 경우에만
                if(check[loc.first] == 0) q.push(loc.first);
            }
        }
    }
    
    sort(summits.begin(), summits.end());
    int min_intensity = 20000000;
    int min_summit = -1;
    
    for (auto summit : summits){
        if (intensity[summit] < min_intensity){
            min_intensity = intensity[summit];
            min_summit = summit;
        }
    }
    return {min_summit, min_intensity};
}
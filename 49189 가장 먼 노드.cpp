#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> connect(n);
    queue<int> q;
    vector<int> distance(n,0); 
    
    for (auto a : edge){
        connect[a[0]-1].push_back(a[1]);
        connect[a[1]-1].push_back(a[0]);
    }
    
    distance[0] = 1;
    q.push(1);
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        int dist = distance[now-1]+1;

        for (auto a : connect[now-1]){
            if (distance[a-1] == 0){
                distance[a-1] = dist;
                q.push(a);
            } 
        }
    }
    
    int max = *max_element(distance.begin(), distance.end());
    
    for (auto a : distance){
        if (a == max) answer++;
    }
    
    return answer;
}
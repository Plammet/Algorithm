#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> road, int K) {
    int answer = 0;
    
    vector<vector<int>> connect(n, vector<int>(n));
    priority_queue<pair<int, int>> pq;
    vector<int> distance(n);
    
    
    fill(distance.begin(), distance.end(), 500001);
    fill(connect.begin(), connect.end(), vector<int>(n, 500001));
    distance[0]=0;

    for(vector<int> r : road){
        int a = r[0]-1;
        int b = r[1]-1;
        
        connect[a][b] = min(connect[a][b], r[2]);
        connect[b][a] = min(connect[b][a], r[2]);
    }
    
    pq.push(make_pair(0,0));
    
    while(!pq.empty()){
        int now = pq.top().second;
        pq.pop();
        
        for(int i = 0; i<n; i++){
            int temp = connect[now][i];
            
            if (temp != 0){
                if (distance[now]+temp < distance[i]){
                    distance[i] = distance[now]+temp;
                    pq.push(make_pair(-distance[i],i));
                }
            }
        }
    }
    
    for (auto dist : distance){
        if (dist <= K) answer++;
    }
    
    return answer;
}
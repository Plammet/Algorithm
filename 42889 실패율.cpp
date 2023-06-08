#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N);
    vector<int> player(N);
    vector<float> failRate(N);
    int total = stages.size();
    
    for (int stage : stages){
        if (stage < N+1) player[stage-1]++;
    }
    
    for (int i = 0; i < N; i++){
        answer[i] = i+1;
        if (total == 0) continue;
        failRate[i] = (float)player[i]/(float)total;
        total -= player[i];
    }
    
    stable_sort(answer.begin(), answer.end(), [&](int a, int b){return failRate[a-1]>failRate[b-1];});
    return answer;
}
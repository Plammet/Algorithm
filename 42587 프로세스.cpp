#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector<int> sorted;

	for (int number : priorities) {
		sorted.push_back(number);
	}

	sort(sorted.begin(), sorted.end(), greater<int>());
    
    int i = 0;
    int j = 0;
    while(true){
        if (priorities[i] == sorted[j]){
            j++;
            if (i == location) return j;
        }
        i = (i+1)%priorities.size();
    }
	return answer;
}
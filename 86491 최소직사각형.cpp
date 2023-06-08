#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int longer = 0;
    int shorter = 0;
    
    for (auto size : sizes){
        if (size[0] > size[1]){
            longer = max(size[0], longer);
            shorter = max(size[1], shorter);
        }
        
        else{
            longer = max(size[1], longer);
            shorter = max(size[0], shorter);
        }    
    }
    
    return longer * shorter;
}
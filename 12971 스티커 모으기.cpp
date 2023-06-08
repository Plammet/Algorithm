#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sticker)
{
    int size = sticker.size();
    if (size == 1) return sticker[0];
    if (size == 2) return max(sticker[0], sticker[1]);
    
    vector<int> dp1 = sticker;
    dp1[1] = sticker[0];
    vector<int> dp2 = sticker;
    dp2[0] = 0;
    
    for (int i = 2; i < size-1; i++){
        dp1[i] = max(dp1[i-2] + sticker[i], dp1[i-1]);
        dp2[i] = max(dp2[i-2] + sticker[i], dp2[i-1]);
    }
    
    dp2[size-1] = max(dp2[size-3] + sticker[size-1], dp2[size-2]);

    return max(dp1[size-2], dp2[size-1]);
}
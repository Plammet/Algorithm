#include<vector>
#include<queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int row = maps.size();
    int col = maps[0].size();

    queue<vector<int>> q;
    vector<vector<int>> distance(row, vector<int>(col,0));

    q.push({0,0});
    distance[0][0] = 1;

    while(true){
        if (q.empty()) break;

        vector<int> now = q.front();
        q.pop();

        int rowNow = now[0];
        int colNow = now[1];
        int dist = distance[rowNow][colNow] + 1;

        if(rowNow == row-1 && colNow == col-1) break;

        if(colNow+1 < col && maps[rowNow][colNow+1] == 1
           && distance[rowNow][colNow+1] == 0)
        {
            q.push({rowNow, colNow+1});
            distance[rowNow][colNow+1] = dist;       
        }

        if(rowNow+1 < row && maps[rowNow+1][colNow] == 1
            && distance[rowNow+1][colNow] == 0)
        {
            q.push({rowNow+1, colNow});
            distance[rowNow+1][colNow] = dist;       
        }

        if(rowNow-1 >= 0 && maps[rowNow-1][colNow] == 1
          && distance[rowNow-1][colNow] == 0)
        {
            q.push({rowNow-1, colNow});
            distance[rowNow-1][colNow] = dist;       
        }

        if(colNow-1 >= 0 && maps[rowNow][colNow-1] == 1
          && distance[rowNow][colNow-1] == 0)
        {
            q.push({rowNow, colNow-1});
            distance[rowNow][colNow-1] = dist;       
        }
    }

    if (distance[row-1][col-1] == 0) return -1;
    else return distance[row-1][col-1];

}
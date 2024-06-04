#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid[0].size(), n = grid.size();
        int maxScore = (1 << (m-1)) * n;
        int c, on;
        for(int j=1; j<m; ++j){
            c = 1 << (m-1-j);
            on = 0;
            for(int i=0;i<n;i++){
                if(grid[i][j] == grid[i][0]){
                    on++;
                }
            }
            maxScore += max(on, n-on) * c;
        }
        return maxScore;
    }
};

int main() {
    vector<vector<int>> v = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    Solution s;
    cout << s.matrixScore(v) << endl;
    return 0;
}
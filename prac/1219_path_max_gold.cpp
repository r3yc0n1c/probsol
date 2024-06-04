#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxGold = 0;
    /*
    Below Neighbor: (row + 0, col + 1)
    Right Neighbor: (row + 1, col + 0)
    Above Neighbor: (row + 0, col - 1)
    Left Neighbor: (row - 1, col + 0)
    */
    // check dir pattern below to left
    int dir[5] = {0, 1, 0, -1, 0};

    int dfsBacktrack(vector<vector<int>> &g, int i, int j, int n, int m)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || g[i][j] == 0)
        {
            return 0;
        }
        // storing the curr val and restoring it later removes the usage
        // of extra tracking arrayfor visited nodes
        int temp = g[i][j], localMax;
        localMax = temp;
        g[i][j] = 0;

        for (int k = 0; k<4; k++)
        {
            localMax = max(localMax, temp + dfsBacktrack(g, i + dir[k], j + dir[k+1], n, m));
        }
        g[i][j] = temp;
        return localMax;
    }
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int m = grid[0].size(), n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maxGold = max(maxGold, dfsBacktrack(grid, i, j, n, m));
            }
        }
        return maxGold;
    }
};

int main()
{
    vector<vector<int>> v = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
    Solution s;
    cout << s.getMaximumGold(v) << endl;
    return 0;
}
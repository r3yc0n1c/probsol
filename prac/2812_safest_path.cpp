/*
OJ: https://leetcode.com/problems/find-the-safest-path-in-a-grid/description
Time: O(n^2)
Space: O(n^2)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;

class Solution {
public:
    bool inBound(int x, int y, int n) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }
    int maximumSafenessFactor(vector<vector<int>> &grid) {
        int n = grid.size(), i, j, newX, newY;
        deque<tuple<int, int, int>> q;
        int dir[5] = {0, 1, 0, -1, 0};

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.emplace_back(i, j, 1);
                }
                grid[i][j]--;
            }
        }

        while (!q.empty()) {
            auto [x, y, safetyFactor] = q.front();
            q.pop_front();

            for (i = 0; i < 4; i++) {
                newX = x + dir[i];
                newY = y + dir[i + 1];
                if (inBound(newX, newY, n) && grid[newX][newY] == -1) {
                    grid[newX][newY] = safetyFactor;
                    q.emplace_back(newX, newY, safetyFactor + 1);
                }
            }
        }

        int minSafetyFactor = grid[0][0];
        q.emplace_back(0, 0, minSafetyFactor);
        
        while (!q.empty()) {
            auto [x, y, thief] = q.front();
            q.pop_front();
            
            minSafetyFactor = min(minSafetyFactor, thief);
            
            if (x == n - 1 && y == n - 1) {
                break;
            }
            
            for (i = 0; i < 4; i++) {
                newX = x + dir[i];
                newY = y + dir[i + 1];
                if (inBound(newX, newY, n) && grid[newX][newY] != -1) {
                    if (grid[newX][newY] < minSafetyFactor) {
                        q.emplace_back(newX, newY, grid[newX][newY]);
                    }
                    else {
                        q.emplace_front(newX, newY, grid[newX][newY]);
                    }
                    grid[newX][newY] = -1;
                }
            }
        }
        return minSafetyFactor;
    }
};

int main()
{
    vector<vector<int>> v = {{0,0,1},{0,0,0},{0,0,0}};
    Solution s;
    cout << s.maximumSafenessFactor(v) << endl;
    return 0;
}